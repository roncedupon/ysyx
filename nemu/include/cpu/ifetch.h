#ifndef __CPU_IFETCH_H__

#include <memory/vaddr.h>

static inline uint32_t inst_fetch(vaddr_t *pc, int len) {
  uint32_t inst = vaddr_ifetch(*pc, len);//拿32bit指令
  (*pc) += len;//⭐⭐⭐同时pc加加
  
  return inst;
}

#endif
