#include <isa.h>
#include <memory/paddr.h>

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {//32位无符号
  // 0x00000297,  // auipc t0,0//这是汇编语言,没学过
  // 0x0002b823,  // sd  zero,16(t0)
  // 0x0102b503,  // ld  a0,16(t0)
  // 0x00100073,  // ebreak (used as nemu_trap)
  // 0xdeadbeef,  // some data
  0x00000413,
  0x00009117,
  0xffc10113,
  0x00c000ef,
  0x00000513,
  0x00008067,
  0xff010113,
  0x00000517,
  0x01c50513,
  0x00113423,
  0xfe9ff0ef,
  0x00050513,
  0x00100073,
  0x0000006f,
};

static void restart() {
  /* Set the initial program counter. */
  cpu.pc = RESET_VECTOR;

  /* The zero register is always 0. */
  cpu.gpr[0] = 0;
}

void init_isa() {
  /* Load built-in image. */
  memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));

  /* Initialize this virtual computer system. */
  restart();
}
