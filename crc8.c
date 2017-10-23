#include "crc8.h"

void init_crc8()
{
    int i,j;
    unsigned char crc;

    for (i=0; i<256; i++) {
        crc = i;
        for (j=0; j<8; j++)
        {
            crc = (crc << 1) ^ ((crc & 0x80) ? DI : 0);
        }
        crc8_table[i] = crc & 0xFF;
        /* printf("table[%d] = %d (0x%X)\n", i, crc, crc); */
    }
    made_table=1;
}

void crc8(uint8_t* crc, uint8_t m)
{
    if (!made_table)
      init_crc8();
  

    *crc = crc8_table[(*crc) ^ m];
    *crc &= 0xFF;
  }