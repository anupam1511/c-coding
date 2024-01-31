#include"header.h"
int main()
{
     int p[2] ; pipe( p) ;
     perror("pipe");
     printf("readend : %d\n",p[0]);
     printf("writeend : %d\n" , p[1]);

     if(fork()==0)
     {
         char s[20] ;
         printf("before read\n");
         read(p[0] , s , sizeof(s)) ;
         printf("%s\n" , s);
     }
     else
     {
          //static use prevention from garbege print and intially 
          //// intialise to null or say 0 .
          char s[20] ;
          printf("in parent before\n");
          scanf("%s",s);
          write(p[1] , s , strlen(s)+1) ;
     }
}
/* output
pipe: Success
readend : 3
writeend : 4
in parent before
before read
hello
hello
*/
