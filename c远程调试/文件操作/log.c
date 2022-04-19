#include"stdio.h"
#define log_write(...) IFDEF(CONFIG_TARGET_NATIVE_ELF, \
  do { \
    extern FILE* log_fp; \
    extern bool log_enable(); \
    if (log_enable()) { \
      fprintf(log_fp, __VA_ARGS__); \
      fflush(log_fp); \
    } \
  } while (0) \
)
//fprintf向指定流写入格式化输入
//fflush是一个在C语言标准输入输出库中的函数，功能是冲洗流中的信息，
//该函数通常用于处理磁盘文件。fflush()会强迫将缓冲区内的数据写回参数stream 指定的文件中。
#define _Log(...) \
  do { \
    printf(__VA_ARGS__); \
    log_write(__VA_ARGS__); \
  } while (0)//__VA_ARGS__:用于在宏替换部分中，表示可变参数列表；,栗子如下



FILE *log_fp = NULL;
void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    Assert(fp, "Can not open '%s'", log_file);
    log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
}


int main(){
	Log("host time spent =  us");
	return 0;
}