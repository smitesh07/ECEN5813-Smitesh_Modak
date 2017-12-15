#include <stdio.h>

char reverse(char *str,int length)
{
 int n=length/2;
 int i,j;
 for(j=0;*(str+j)!=0;++j);
 if(j==length)
 {
  { for(i=0;i<=n-1;i++)
    {char temp=*(str+i);
     char temp1=*(str+length-i-1);
     *(str+i)=temp1;
     *(str+length-i-1)=temp;
     }
   }
  return '0';
 }
  else return 'A';
}

void main ()
{char a,val,val1,val2;
 char str1[]="This is a string.";
 val=reverse(str1,17);
 char str2[]="some NUMmbers12345";
 val1=reverse(str2,18);
 char str3[]="Does it reverse \n\0\t correctly?";
 val2=reverse(str3,30);
 printf("%c\n",val);
 printf("%c\n",val1);
 printf("%c\n",val2);
}

