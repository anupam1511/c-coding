#include<stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct student
{
   char name[30] ;
   int *mark ;
   float average ;
}stu;
int a ; stu *p;  int b ;float high = 0 , low = 0 ;
void insert(void)
{
   srand(getpid());
   printf("enter the number of subject for student\n");
   scanf("%d",&b);

    printf("enter the number of student u want for detailing\n");
    scanf("%d",&a);
    p = malloc(sizeof(stu)*a) ;
    for(int i = 0 ; i < a ; i++)
    {
         printf("enter the name of student %d \n",i);
         scanf("%s",p[i].name);

             p[i].mark=(int *)malloc(sizeof(int)*b);
             for(int j = 0 ; j < b ; j++)
             {
                 printf("enter the marks of subject %d :", j);
                // scanf("%d" , &p[i].mark[j]);
                 p[i].mark[j] = rand()%1000 ;
             }

    }




}
void print()
{
        for(int i = 0 ; i < a ; i++)
        {
         printf(" the name of student %d \n",i);
         printf("%s\n",p[i].name);
         for(int j = 0 ; j < b ; j++)
         {
             printf(" marks of subject %d :", j);
             printf("%d\n" , p[i].mark[j]);
         }
         printf("%.2f",p[i].average);
         printf("\n\n");
        }
        printf("highest per : %.2f  lowest per %.2f" , high , low);

}
void average()
{    float sum = 0 ;
     for(int i = 0 ; i < a ; i++)
     {

      for(int j = 0 ; j < b ; j++)
      {
         sum +=  p[i].mark[j];
      }
      p[i].average = sum/b;

     }

}
void highlow()
{
     for(int i = 0 ; i < a ; i++)
     {
        if(high<p[i].average)
        {
            high = p[i].average ;
        }
     }
     low = p[0].average ;
     for(int i  = 0  ; i < a-1  ; i++)
     {
        if(low  > p[i+1].average)
        {
                                                                                                                                                                                                                                                                                                                                                     12,51         Top
  low = p[i].average ;
        }
     }
}
int main()
{
     insert();
     average() ;
     highlow();
     print();

}
