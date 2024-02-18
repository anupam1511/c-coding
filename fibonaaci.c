// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    int min = 3 , max = 7 , a = 0 , b = 1 , c = 0 ; 
    for(int i = 0 ; i < max ; i++)
    {
        c = a +  b ; 
        a = b ; 
        b = c ; 
        if(i>=min)
        printf("%d\t",c);
    }

    return 0;
}
