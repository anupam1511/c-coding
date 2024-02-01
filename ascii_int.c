#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{

      char s[3] = "12" ;
      char *p = s ;int res = 0 ;
     //puts(s) ; 
     while(*p>='0' && *p<='9')
     {
          res = (res*10)+(*p-'0') ;
          p++;
     }
     printf("%d\n" , res);


}
