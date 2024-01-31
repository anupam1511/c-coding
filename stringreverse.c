#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *getstring()
{
      char *p = NULL ;
      char ch ;
      int cnt = 0 ;
     do{
          p = realloc(p , sizeof(char)*(cnt+1)) ;
          p[cnt] = getchar() ;
          //cnt++;

       }while((p[cnt++])!='\n') ;
     p[cnt] = '\0' ;
    // printf("%s",p) ; perfect
    //puts(p);  // using this giving space in terminal after print the op.
    return p ;
}
void rev(char *p)
{

        int i , j ;
        char temp ;
    {
       for(i = 0 , j = strlen(p)-1;i<(strlen(p)/2) ; i++ , j--)
       {
           temp = p[i] ;
           p[i] = p[j] ;
           p[j] = temp ;
       }
    }

}
int main()
{
   char *s ;
   printf("enter your string \n");
   s = getstring() ;
   puts(s);
   rev(s) ;
   puts(s);
}
~                                                                                                                                              
~                                                                                                                                              
~                                                                                                                                              
          
