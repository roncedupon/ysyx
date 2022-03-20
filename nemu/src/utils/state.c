#include <utils.h>

NEMUState nemu_state = { .state = NEMU_STOP };//默认state是1

int is_exit_status_bad() {
  int good = (nemu_state.state == NEMU_END && nemu_state.halt_ret == 0)||(nemu_state.state == NEMU_QUIT);
    printf("结束状态输出:%d_%d_%d",nemu_state.state,nemu_state.halt_ret,nemu_state.state);
  return !good;//2_0_2是对的,,,1_0_1
}
