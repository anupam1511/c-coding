// Online C compiler to run C program online
#include <stdio.h>
#include<math.h>
void fibonacci(int a)
{
    int copy = a , count = 0 , result = 0 ; 
    while(copy)
    {
        count++;
        copy /= 10 ; 
    }
   
    copy = a ;
   
    while(copy)
    {
        int mod ;
        mod = copy%10 ;
        result  = result + pow(mod,count) ;
        copy /= 10 ;
      
    }
    if(a==result) printf("armstrong") ;
    else printf("not armstrong");
}
int main() {
    // Write C code here
    // armstrong
    int num = 153 ;
    fibonacci(num);

    return 0;
}
