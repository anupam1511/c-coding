#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int sort(int *p , int n)
{
        int temp ;
     for(int i = 0 ; i < n ; i++)
             for(int j = 0 ; j<n-i ; j++)
             {
                 if(p[j]>p[j+1])
                 {
                    temp = p[j] ;
                    p[j] = p[j+1] ;
                    p[j+1] = temp ;
                 }
             }

}
int main()
{
        int p[2] ;
        pipe(p) ;
        perror("pipe");
        if(fork()==0)
        {
           int arr[5] ;
           //sleep(9) ; 
           read(p[0] , arr , 4*5) ;
           for(int i = 0 ; i < 5 ; i++)
           {
              printf("%d\t" , arr[i]) ;
           }

        }
        else
        {
           int a[5] ;
           printf("enter 5 integer array\n");
           for(int i = 0 ; i < 5 ; i++)
           {
              scanf("%d" , &a[i]);
           }
           sort(a , 5) ;
           write(p[1] , a , sizeof(int)*5) ;
           wait(0);

        }
}
// use wait(0) for completion of child process ok ...
