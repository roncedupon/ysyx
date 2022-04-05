#include "local-include/reg.h"
#include <cpu/cpu.h>
#include <cpu/ifetch.h>
#include <cpu/decode.h>
#define R(i) gpr(i)//(cpu.gpr[check_reg_idx(idx)])
//这个i只能时0-31,R(i)直接对第i个寄存器进行操作
/*
typedef struct {
  word_t gpr[32];
  vaddr_t pc;
} riscv64_CPU_state;
*/
#define Mr vaddr_read//虚拟内存读
#define Mw vaddr_write//虚拟内存写,paddr应该就是物理内存读写
//向起始地址+地址长度内存内写入数据
enum {
  TYPE_I, TYPE_U, TYPE_S,TYPE_J,//指令类型,好像还有J类型
  TYPE_N, // none
};
#define src1R(n) do { *src1 = R(n); } while (0)//cpu.gpr[check_reg_idx(n)]--------获取第n个寄存器的值存到src1
#define src2R(n) do { *src2 = R(n); } while (0)//同上
#define destR(n) do { *dest = n; } while (0)//获取寄存器的名字,destR和destI好像都一样
//上下两部分,上面是从寄存器中拿值给src1,2,下面就是简单地把值给src1
#define src1I(i) do { *src1 = i; } while (0)//i型指令,直接拿立即数计算
#define src2I(i) do { *src2 = i; } while (0)//同上
#define destI(i) do { *dest = i; } while (0)//同上
//#define destJ(i) do { *dest = i; } while (0)
//#define src1J() do {}

//sext+bits:截取i[31:20]位,并且前面补零成为64bit
static word_t immI(uint32_t i) { return SEXT(BITS(i, 31, 20), 12); }//拿到32位指令的12~31位,放低位,高位补零
static word_t immU(uint32_t i) { return SEXT(BITS(i, 31, 12), 20) << 12; }//获取U型指令的立即数   
static word_t immS(uint32_t i) { return (SEXT(BITS(i, 31, 25), 7) << 5) | BITS(i, 11, 7); }//SEXT取低length位
static word_t immJ(uint32_t i) { return (SEXT((BITS(i,31,31)<<20)+(BITS(i,30,21)<<1)+(BITS(i,20,20)<<11)+(BITS(i,19,12)<<12),21));}

/*

*/
static void decode_operand(Decode *s, word_t *dest, word_t *src1, word_t *src2, int type) {//解码操作数
//对结构体s,dest,src1,src2,type进行操作
  uint32_t i = s->isa.inst.val;
  int rd  = BITS(i, 11, 7);//对应指令格式
  int rs1 = BITS(i, 19, 15);//
  int rs2 = BITS(i, 24, 20);//
  destR(rd);
  switch (type) {//
    case TYPE_I: src1R(rs1);     src2I(immI(i)); break;//如果是i型指令,拿到rs1寄存器的值,
    case TYPE_U: src1I(immU(i)); break;//
    case TYPE_S: destI(immS(i)); src1R(rs1); src2R(rs2); break;
    case TYPE_J: src1I(immJ(i));break;//j型指令需要将pc的下一条指令存入一个寄存器里,这个寄存器由rd给出,然后pc再加上立即数实现指令的跳转
  }
}
static int decode_exec(Decode *s) {
  word_t dest = 0, src1 = 0, src2 = 0;
  s->dnpc = s->snpc;//snpc在获取指令的时候就变成了目前pc+4了,出去后pc就变成了s->dnpc
//先让dnpc等于这个snpc,也就是下一个pc,也就是pc+4
#define INSTPAT_INST(s) ((s)->isa.inst.val)
//接下来解码,拿到指令中的数据
#define INSTPAT_MATCH(s, name, type, ... /* body */ ) { \
  decode_operand(s, &dest, &src1, &src2, concat(TYPE_, type)); \
  __VA_ARGS__ ; \
}//输入s(指令),获取dest,获取src1和src2(对应寄存器内元素)
//每一行最后的斜杠表示在这一行和下一行是连着的---dest=rd,src1=R[rs1],src2=R[rs2],src1,2已经是读出来的

  INSTPAT_START();
  INSTPAT("??????? ????? ????? ??? ????? 00101 11", auipc     , U, R(dest) = src1 + s->pc);//这个src1相当于immU(32位指令)-
  //auipc:pc加立即数--符号位扩展到20位立即数加到pc上,结   写入x[rd]
  INSTPAT("??????? ????? ????? 011 ????? 00000 11", ld        , I, R(dest) = Mr(src1 + src2, 8));
  INSTPAT("??????? ????? ????? 011 ????? 01000 11", sd        , S, Mw(src1 + dest, 8, src2));
  //INSTPAT("",li,      
  //li,立即数加载,使用尽可能少的指令加载立即数到x[rd]   
  INSTPAT("??????? ????? ????? 000 ????? 00100 11", addi      , I, R(dest)=src1+src2);
  //INSTPAT("??????? ????? ????? ??? ????? 00100 11", lui       , I, R(dest)=src1+immI(s->isa.inst.val));
  //jal--跳转并连接--把下一条指令的地址(pc+4)存到目标寄器里，然后把pc设置为当前值加上符号位扩展的offset。
  INSTPAT("??????? ????? ????? ??? ????? 11011 11", jal       , J, R(dest)=s->dnpc;s->dnpc+=src1-4);//将s->dnpc+=src1-4改成s->dnpc=src1+s->pc
  INSTPAT("??????? ????? ????? 000 ????? 11001 11", jalr      , I, word_t t=s->snpc;s->dnpc=src1+immI(s->isa.inst.val);R(dest)=t);
  INSTPAT("0000000 00001 00000 000 00000 11100 11", ebreak    , N, NEMUTRAP(s->pc, R(10))); // R(10) is $a0
  INSTPAT("??????? ????? ????? ??? ????? ????? ??", inv       , N, INV(s->pc));
  

  INSTPAT_END();

  R(0) = 0; // reset $zero to 0

  return 0;
}

int isa_exec_once(Decode *s) {
  s->isa.inst.val = inst_fetch(&s->snpc, 4);//从这个起始地址中拿到32bit数据
  return decode_exec(s);
}
