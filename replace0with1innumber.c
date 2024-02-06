#include<stdio.h>
#include<math.h>
int main()
{
   int x = 10804090 ;
   int n = x ; 
   int g , i = -1  ;
   while(n)
   {
       g = n % 10 ; 
       i++ ; 
       if(g==0)
       {
           x = x + pow(10 , i) ;  
       }
       n = n/10 ;
   }
   printf("%d" , x) ;
}
/*anupam@anupam-VirtualBox:~$ cc replacewithone.c -lm
anupam@anupam-VirtualBox:~$ ./a.out 
11814191anupam@anupam-VirtualBox:~$ */


