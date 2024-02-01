#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
char *getstring()
{
    char *p=NULL ;
    int cnt=0;
    do{
          p = realloc(p , 1*(cnt+1) );
          p[cnt] = getchar();

      }while(p[cnt++]!='\n');
    p[cnt-1]='\0';
    return p ;
}
void rev(char *p)
{int i , j  ;
        char temp ;
      for(i=0 , j=strlen(p)-1;i<(strlen(p)/2) ;i++,j--)
      {
             temp = p[i] ;
             p[i] = p[j] ;
             p[j] = temp ;

      }
}
void revword(char *p)
{
   char *s ;
   //char *f = p ;
 //  puts(p);
   printf("enter the word to reverse\n");
   s = getstring() ;
 //  puts(s);

   for(    ; p=strstr(p,s) ; p++)
   {

//      printf("hello\n");
//          printf("%s" , p) ;


        {///printf("yes");
            if(((*(p-1))==' ') || (*p==p[0]) && ((*(p+strlen(s))==' '  || (*(p+strlen(s)))=='\0')))
            {
                 //printf("%s",p);
                 rev(s) ;
                 //puts(s) ; 
                 strncpy(p,s,strlen(s));


            }
        }
   }
   //if(p==NULL) printf("not found\n");
}
int main()
{
     char *string ;
     printf("enter your string\n");
     __fpurge(stdin);
     string = getstring();
     //printf("%s",string);
     revword(string);
     puts(string);
}
