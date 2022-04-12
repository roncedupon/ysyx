#include <isa.h>
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {//64
  for(int i=0;i<32;i++){
    printf("%s寄存器:0x%016lx\n",regs[i], cpu.gpr[i]);
  }
}

word_t isa_reg_str2val(const char *s, bool *success) {
  int i=0;
  if(!strcmp(s+sizeof(char),"0")){
     printf("%s寄存器:0x%016lx\n",regs[i], cpu.gpr[i]);//输出寄存器的值
     return cpu.gpr[i];//单独处理$0
  }
  if(!strcmp(s+sizeof(char),"PC")){
    printf("PC寄存器:0x%016lx\n", cpu.pc);//输出寄存器的值
     return cpu.pc;//单独处理$0
  }
  printf("%s_____%s\n",s+sizeof(char),regs[5]);
  while(strcmp(s+sizeof(char),regs[i]))i++;//获取到s所在regs中的位置
  printf("%s寄存器:0x%016lx\n",regs[i], cpu.gpr[i]);//输出寄存器的值
  return cpu.gpr[i];
}
