#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "sdb.h"
#include "memory/paddr.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;//静态的,一直保留在函数里

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(nemu) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}
//单步调试
static int cmd_si(char *args){
  char *arg_to_deal = strtok(args," ");//将args按空格分开,并且把args第一个给arg_to_deal
  if(arg_to_deal==NULL){
    cpu_exec(1);
    printf("默认执行一步\n");
    return 0;
  }
  else{
    int num = atoi(arg_to_deal);
    cpu_exec(num);
    printf("OK");
    return 0;
  }    
}
//单步调试--end

//打印寄存器(打印寄存器状态,打印监视点信息)
static int cmd_info(char *args){
  char *arg = strtok(args," ");//获取info 后面的命令参数
  printf("%s----寄存器状态",arg);
  isa_reg_display();//调用这个函数api
  return 0;
  //输入info 就能打印所有寄存器
}
//打印寄存器--end
//扫描内存--begin
static int cmd_EXPR(char*args){
//地址对比
/*
  0x00000297,  // auipc t0,0
  0x0002b823,  // sd  zero,16(t0)
  0x0102b503,  // ld  a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data

*/

  //格式:x N EXPR
  //求出表达式EXPR的值, 将结果作为起始内存地址, 以十六进制形式输出连续的N个4字节
  //需要include文件:paddr.h
  int number;
  paddr_t address;
  sscanf(args,"%d %x",&number,&address);//用stroke也一样
//一个地址的值对应8字节,一个数据被存在32字节里(4个地址)
  //扫描内存:x 10 0x80000000
  for(int i=0;i<number;i++){
    printf("0x%016x的数据:",address+i*4);
    for(int j=0;j<4;j++)
    printf("0x%02lx ",paddr_read(address+i*4+j,1));//原来是address+i,输出结果不太对,后来改为i*4就对上了
    printf("\n");
  }
  
  //printf("%x=============================fuck",);
  return 0;
}
//扫描内存--end

static int cmd_q(char *args) {
  return -1;//这里没问题--cmd_q一直返回的是-1
}


static int cmd_help(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NEMU", cmd_q },
  {"si","单步调试",cmd_si},
  {"info","打印寄存器",cmd_info},
  {"x","扫描内存",cmd_EXPR}

  /* TODO: Add more commands */

};

#define NR_CMD ARRLEN(cmd_table)//cmd_table的地址长度

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");// char *strtok(char *str, const char *delim) 分解字符串 str 为一组字符串，delim 为分隔符。
    if (cmd == NULL) { continue; }//先从命令行读入cmd,比如si 1酱紫的命令
    //然后使用strok将这个命令按空格分开,这时cmd的值就是si这一条命令

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;//这个args拿到si后面的参数给handler用
    if (args >= str_end) {
      args = NULL;
    }

#ifdef CONFIG_DEVICE
    extern void sdl_clear_event_queue();
    sdl_clear_event_queue();
#endif

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {//若str1==str2就返回0
        if (cmd_table[i].handler(args) < 0) { return; }//q的话永远返回-1---就能直接return
        break;//如果不return,就说明命令无效
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}

void init_sdb() {
  /* Compile the regular expressions. */
  init_regex();

  /* Initialize the watchpoint pool. */
  init_wp_pool();
}
