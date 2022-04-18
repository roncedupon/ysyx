#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
//#include<../../../monitor/sdb/watchpoint.h>
/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
bool watch_point_changed();//声明
void watch_point_test();

CPU_state cpu = {};//在此初始化cpu
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;
// bool watch_point_changed(WP*head){
//   printf("trace_and_difftest函数执行\n");
//   printf("%d--------------\n",head.NO);
//   return false;
// }

void device_update();
//每当cpu_exec()的循环执行完一条指令, 都会调用一次trace_and_difftest()函数. 
static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
  if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
#endif
  if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
  IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
  //4.1扫描监视点
  if(watch_point_changed()){
    printf("触发了fuck断点,你tm想干啥?\n");
    watch_point_test();
    nemu_state.state=NEMU_STOP;
  }
  
}

//指令环形缓冲区


static void exec_once(Decode *s, vaddr_t pc) {//获取pc的地址
printf("当前cpu指向的地址是%lx\n",pc);
  s->pc = pc;//pc的位置--将pc当前指向的位置存入s->pc
  s->snpc = pc;//在执行之前只是把snpc给了s,将pc的位置存给snpc,静态pc并没有给dnpc的值
  isa_exec_once(s);//执行
  cpu.pc = s->dnpc;//cpu的pc寄存器拿到下一条指令地址
#ifdef CONFIG_ITRACE
  char *p = s->logbuf;//log_buf[128]
  p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);//这里将指令记录到log里
//C 库函数 int snprintf(char *str, size_t size, const char *format, ...)
// 设将可变参数(...)按照 format 格式化成字符串，
//并将字符串复制到 str 中，size 为要写入的字符的最大数目，超过 size 会被截断。
//返回值是本来要写入的字符串长度(实际长度加一(\0结束符))
//https://www.runoob.com/cprogramming/c-function-snprintf.html
  int ilen = s->snpc - s->pc;//指令长度
  int i;
  uint8_t *inst = (uint8_t *)&s->isa.inst.val;
  for (i = 0; i < ilen; i ++) {
    p += snprintf(p, 4, " %02x", inst[i]);
    printf("-------------------------写入log");//log
  }
  printf("----------------------------4log写入完成");
  int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
  int space_len = ilen_max - ilen;
  if (space_len < 0) space_len = 0;
  space_len = space_len * 3 + 1;
  memset(p, ' ', space_len);
  p += space_len;

  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
      MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst.val, ilen);//反汇编指令
#endif
}

static void execute(uint64_t n) {//输入执行次数
  Decode s;//创建Decode s结构体,执行一次创建一次
  for (;n > 0; n --) {
    exec_once(&s, cpu.pc);//输入pc的地址
    g_nr_guest_inst ++;
    trace_and_difftest(&s, cpu.pc);
    if (nemu_state.state != NEMU_RUNNING) break;
    IFDEF(CONFIG_DEVICE, device_update());
  }
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%ld", "%'ld")
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
  printf("这个函数在cpu-exec.c中\n-------------------------------");
  isa_reg_display();
  statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {//如果输入-1就全部执行了
  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (nemu_state.state) {
    case NEMU_END: case NEMU_ABORT:
      printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
      return;
    default: nemu_state.state = NEMU_RUNNING;
  }

  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start;

  switch (nemu_state.state) {
    case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

    case NEMU_END: case NEMU_ABORT:
      Log("nemu: %s at pc = " FMT_WORD,
          (nemu_state.state == NEMU_ABORT ? ASNI_FMT("ABORT", ASNI_FG_RED) :
           (nemu_state.halt_ret == 0 ? ASNI_FMT("HIT GOOD TRAP", ASNI_FG_GREEN) :
            ASNI_FMT("HIT BAD TRAP", ASNI_FG_RED))),
          nemu_state.halt_pc);
      // fall through
    case NEMU_QUIT: statistic();
  }
}
