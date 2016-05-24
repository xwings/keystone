#include <keystone/keystone.h>
int main(int argc, char **argv) {
  int ks_arch = KS_ARCH_HEXAGON, ks_mode = KS_MODE_LITTLE_ENDIAN;
  unsigned char assembly[] = {
    'R', '1', '9', '=', 0xff, '#', 'R', '+', 'R', '1',
    'o', 'Q', '^', '+', 'R', 0x00,
  };
  ks_engine *ks;
  ks_err err = ks_open(ks_arch, ks_mode, &ks);
  if (!err) {
    size_t count, size;
    unsigned char *insn;
    ks_asm(ks, (char *)assembly, 0, &insn, &size, &count);
  }
  ks_close(ks);
}
