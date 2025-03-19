// Amogh Bantwal
// amoghb07@uw.edu

#include "stdio.h"
#include <inttypes.h>

void PrintBytes(void* val, int size);

int main(int argc, char* argv[]) {
  char char_val = '0';
  int int_val = 1;
  float float_val = 1.0;
  double double_val  = 1.0;

  typedef struct {
    char char_val;
    int int_val;
    float float_val;
    double double_val;
  } Ex2Struct;

  Ex2Struct struct_val = { '0', 1, 1.0, 1.0 };

  PrintBytes(&char_val, sizeof(char));
  PrintBytes(&int_val, sizeof(int));
  PrintBytes(&float_val, sizeof(float));
  PrintBytes(&double_val, sizeof(double));
  PrintBytes(&struct_val, sizeof(struct_val));

  return 0;
}


void PrintBytes(void* val, int size) {
    unsigned char* ptr = (unsigned char *) val;
    printf("The %d bytes starting at %p are: ", size, val);
    for (int i = 0; i < size; i++) {
        printf("%02x ", ptr[i]);
    }
    printf("\n");
}
