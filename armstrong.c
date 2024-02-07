#include<stdio.h>
#include<math.h>
#include<stdio_ext.h>
#include<stdlib.h>
int armstrong(void)
{char num[10]  , copy,result=0, count  = 0  ,numm , g ;
      printf("enter your number\n");
      scanf("%s" , num);
      for(int i = 0  ; num[i] ; i++)
      {
           if( num[i]<'0' || num[i]>='9')
                   return 39 ;
      }
      numm  = atoi(num) ;

      copy = numm;
      while(copy)
      {
           count++ ;
           copy = copy/10 ;
      }
      copy = numm;
      while(copy)
      {
           g = copy % 10 ;
           result = result + pow(g,count) ;
           copy = copy/10 ;
      }
      if(result==numm) printf("armstrong\n");
      else printf("not an armstrong\n");

      return 1 ;

}
int main()
{
     char choise ;int collect ;
     while(1)
     {
      printf("enter choise  1.find_armstrong 2.exit\n");
      __fpurge(stdin) ;
      scanf("%c" , &choise);
      if(choise>='0' && choise<='9')
      {
      switch(choise)
      {
          case '1' : collect = armstrong() ;
                     if(collect == 39) printf("please enter numbers only upto 8 digits\n") ;
                   break ;
          case '2' : return 0 ;
          default : printf("can u please enter the write choise\n");
      }
      }
      else
      {
         printf("please enter number between 0 to 9\n");
      }

     }


}
