// Online C compiler to run C program online
#include <stdio.h>
#include<math.h>
/* a perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. For instance, 6 has divisors 1, 2 and 3 (excluding itself), and 1 + 2 + 3 = 6, so 6 is a perfect number.*/
void perfectnum(int a)
{   int result  = 0 ; 
    for(int i = 1 ; i < a ; i++)
    {
        if(a%i==0)
        result = result + i ;
    }
    if(result==a) printf("%d perfect number\n",a);
}
int main()
{
    for(int i = 2 ; i < 10000000 ; i++)
    perfectnum(i);
    
    return 0 ; 
}
