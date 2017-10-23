#include <stdio.h>
#include <netinet/in.h>

#define GP 0x107    // x^8 + x^2 + x + 1
#define DI 0x07

uint8_t crc8_table[256];
uint8_t made_table;

void init_crc8();
void crc8(uint8_t* crc, uint8_t m);

