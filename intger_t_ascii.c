// user input an integer by stdin buffer and convert it to string 

#include<stdio.h>
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
         p[i] = (u%10)+48 ;

        u = u/10;
    }
    p[count] = '\0';
    for( i = 0 ; i < count ; i++)
    {
         printf("ascii symbol : %c , ascii value in decimal :  %d\n" , p[i] , p[i]);
    }
    printf("\n");
   // printf("%c" , p[3]); // null not able to print ok....
   //
}

/* output   
enter your integer
123
total integer number are : 3
ascii symbol : 1 , ascii value in decimal :  49
ascii symbol : 2 , ascii value in decimal :  50
ascii symbol : 3 , ascii value in decimal :  51
 */
