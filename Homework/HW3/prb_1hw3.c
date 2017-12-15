#include <stdio.h>

void main()
{ int index;
  unsigned char arr [8] = {0xEE,0x12,0x77,0xBE,0x66,0x54,0x33,0xF0};
  unsigned char *ptr = arr;
  *ptr = 0xF1 & 127;
  ptr++;
  *ptr+=17;
  ptr+=2;
  *ptr=15%4;
  ptr--;
  *ptr>>=4;
  ptr=(char*)(ptr+3);
  *ptr=(1<<5) | (4<<2);
  ptr+=2;
  *((char*)ptr)=22;
  ptr=&arr[0];
  for(index=0;index<8;index++)
  {
    printf("Addr: %d %x\n",(100+index),*ptr++);
  }
}

