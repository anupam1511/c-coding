#include<stdio.h>
#include<math.h>
int main()
{
   int x = 101 ;
   int n  = 0 ; 
   int g , i = -1  ;
   while(x)
   {
       g = x % 10 ; 
       i++ ; 
       if(g==1)
       {
           n = n + pow(2 , i) ;  
       }
       x = x/10 ;
   }
   printf("%d" , n) ;
}
/*anupam@anupam-VirtualBox:~$ cc replacewithone.c -lm
anupam@anupam-VirtualBox:~$ ./a.out 
5anupam@anupam-VirtualBox:~$ */
