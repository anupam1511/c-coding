#include<stdio.h>
#include<string.h>
char *reverse(char *p , int count)
{
        static char s[30] ;
        for(int i = 0 , j = strlen(p)-1; i < strlen(p)/2 ; i++ , j--)
        {
           char temp = p[i] ;
           p[i] = p[j] ;
           p[j] = temp ;
        }
        printf("%s\n" , p);
        --count ;
        strcat(s,p) ;
        s[strlen(s)] = ' ';
        s[strlen(s)+1] = '\0' ;
        //strcat(s,"12");
        if(count==1)
        {
                s[strlen(s)] = '\0' ;
                return s ;
        }

}
int main()
{
    char str[] = "siht si a elppa" ;
    int count = 0 ;
    char *u = str ;
    while(u = strchr(u,' '))
    {
        count++ ;
        u++;
    }
    printf("%d" , count);

    char *p = strtok(str," ") ;
    while(p!=NULL)
    {
            u = reverse(p , count) ;
            p = strtok(NULL," ");
    }
    printf("%s\n" , u);
    strcpy(str,u);
    printf("%s\n",str);
}
