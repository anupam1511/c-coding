#include<stdio.h>
#include<string.h>
void vowel(char *p)
{
        char str[] = "AEIOUaeiou";
        if(strchr(str,p[0]) && (strchr(str,p[strlen(p)-1])))
        printf("%s\n" , p);
}
int main()
{
    char str[] = "this is a apple icecreami" ;
    char *p = strtok(str," ") ;
    while(p!=NULL)
    {
            vowel(p) ;
        p = strtok(NULL," ");
    }

  /* for checking purpose 
   * for(int i  = 0 ; i <= 24 ; i++)
   {
      if(str[i]=='\0')
      {
        printf("\\0") ;
      }
      else
      {
         printf("%c",str[i]);
      }
   }*/
}
