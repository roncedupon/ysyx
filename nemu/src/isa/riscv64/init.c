#include <isa.h>
#include <memory/paddr.h>

// this is not consistent with uint8_t
// but it is ok since we do not access the array directly
static const uint32_t img [] = {//32位无符号
  0x00000297,  // auipc t0,0//这是汇编语言,没学过
  0x0002b823,  // sd  zero,16(t0)
  0x0102b503,  // ld  a0,16(t0)
  0x00100073,  // ebreak (used as nemu_trap)
  0xdeadbeef,  // some data
//0x <_start,
// 0x00000413,
// 0x00009117,
// 0xffc10113,
// 0x120000ef,
// //0x <check>,
// 0x00050463,
// 0x00008067,
// 0xff010113,
// 0x00100513,
// 0x00113423,
// 0x0fc000ef,
// //0x <main>:,
// 0xfd010113,
// 0x00913c23,
// 0x00000497,
// 0x18848493,
// 0x02813023,
// 0x01213823,
// 0x01313423,
// 0x02113423,
// 0x01413023,
// 0x00000917,
// 0x12c90913,
// 0x00000997,
// 0x18498993,
// 0x00048413,
// 0x00042503,
// 0x00092783,
// 0x00440413,
// 0x0075551b,
// 0x40f50533,
// 0x00153513,
// 0xf99ff0ef,
// 0x00490913,
// 0xff3410e3,
// 0x00000997,
// 0x0d498993,
// 0x00000917,
// 0x12c90913,
// 0x00400413,
// 0x00c00a13,
// 0x00092503,
// 0x0009a783,
// 0x00490913,
// 0x4085553b,
// 0x40f50533,
// 0x00153513,
// 0x0014041b,
// 0xf59ff0ef,
// 0x00498993,
// 0xfd441ee3,
// 0x00000917,
// 0x0d490913,
// 0x00400413,
// 0x00c00993,
// 0x0004a503,
// 0x00092783,
// 0x00448493,
// 0x0085553b,
// 0x40f50533,
// 0x00153513,
// 0x0014041b,
// 0xf21ff0ef,
// 0x00490913,
// 0xfd341ee3,
// 0x02813083,
// 0x02013403,
// 0x01813483,
// 0x01013903,
// 0x00813983,
// 0x00013a03,
// 0x00000513,
// 0x03010113,
// 0x00008067,
// //0x <halt>:,
// 0x00050513,
// 0x00100073,
// 0x0000006f,
// //0x <_trm_i,
// 0xff010113,
// 0x00000517,
// 0x02050513,
// 0x00113423,
// 0xeedff0ef,
// 0x00050513,
// 0x00100073,
// 0x0000006f,



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
