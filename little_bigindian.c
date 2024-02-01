#include<stdio.h>
int main()
{
    int x = 1 ;
    char *p ;
            p = (char *)&x ;
 /*   for(char i = 0 ; i < 32 ; i++)
    {
        printf("%d" , (x>>i)&1);
    }*/
            if(*p==1) printf("little-endian\n") ;
            else printf("big-indian\n");
}

/*cast to pointer from integer of different size [-Wint-to-pointer-cast]
       p = (char *)x ;
       like why this error is because x is an integer not an address means thum integer ko ek pointer bananna cha rahe ho and dusra
       ki int se thum usko char me type cast kar raje ho size
*/
