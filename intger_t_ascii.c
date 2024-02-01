#include<stdlib.h>
int main()
{
    int u ;
    printf("enter your integer\n");
    scanf("%d",&u);
    int copy = u ; int count = 0 ;
    while(copy)
    {
         count++ ;
         copy /= 10 ;
    }
    printf("total integer number are : %d\n" , count);
    char *p ;
    p = malloc(count+1) ;


    int i ;
    for( i = count-1 ; i >= 0 ; i--)
    {
         p[i] = u%10 ;

        u = u/10;
    }
    p[count] = '\0';
    for( i = 0 ; i < count ; i++)
    {
         printf("%d" , p[i]);
    }
    printf("\n");
   // printf("%c" , p[3]); // null not able to print ok....
   //
}

/* output   
enter your integer
123456
total integer number are : 6
123456*/

