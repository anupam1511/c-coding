#include<stdio.h>
int main()
{
   char s[30] = "this hello anupam grapes" ;
   char *p = s ;
  int count = -1 , i =  0 , j  ;
   for( ; *p ; p++)
   {
       if(*p==' ')
       { j = count ;
          for(i , j ; i/2 < j/2; i++ , j--)
          {
             printf("%c %c \n" , s[i] , s[j]);
             char temp = s[i] ;
             s[i] = s[j] ;
             s[j] = temp ;

          }
         i = count + 2 ;

       }

       count++ ;
   }
        j = count ;
          for(i , j ; i/2 < j/2; i++ , j--)
          {
             printf("%c %c \n" , s[i] , s[j]);
             char temp = s[i] ;
             s[i] = s[j] ;
             s[j] = temp ;
          }

   puts(s);
}
