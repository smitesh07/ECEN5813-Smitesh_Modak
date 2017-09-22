#include <stdio.h>
#include <stdint.h>
char print_arch_data()
{
 char a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11;
 char a12,a13,a14,a15,a16,a17,a18,a19,a20,a21;
 a1=sizeof(char);
 printf("char:%d\n",a1);
 a2=sizeof(int);
 printf("int:%d\n",a2);
 a3=sizeof(float);
 printf("float:%d\n",a3);
 a4=sizeof(double);
 printf("double:%d\n",a4);
 a5=sizeof(short);
 printf("short:%d\n",a5);
 a6=sizeof(long);
 printf("long:%d\n",a6);
 a7=sizeof(long int);
 printf("long int:%d\n",a7);
 a8=sizeof(long long);
 printf("long long:%d\n",a8);
 a9=sizeof(int8_t);
 printf("int8_t:%d\n",a9);
 a10=sizeof(uint8_t);
 printf("uint8_t:%d\n",a10);
 a11=sizeof(uint16_t);
 printf("unit16_t:%d\n",a11);
 a12=sizeof(uint32_t);
 printf("uint32_t:%d\n",a12);
 a13=sizeof(char*);
 printf("char*:%d\n",a13);
 a14=sizeof(int*);
 printf("int*:%d\n",a14);
 a15=sizeof(float*);
 printf("float*:%d\n",a15);
 a16=sizeof(void*);
 printf("void:%d\n",a16);
 a17=sizeof(void**);
 printf("void*:%d\n",a17);
 a18=sizeof(int8_t*);
 printf("int8_t*:%d\n",a18);
 a19=sizeof(int16_t*);
 printf("int16_t:%d\n",a19);
 a20=sizeof(int32_t*);
 printf("int32_t:%d\n",a20);
 a21=sizeof(size_t);
 printf("size_t:%d\n",a21);
 return 0;
} 
 
void main()
{char size=print_arch_data();
}
