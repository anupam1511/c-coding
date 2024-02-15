#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
   char name[30] ;
   int *mark ;
}stu;
int a ; stu *p;  int b ;
void insert(void)
{

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
                 scanf("%d" , &p[i].mark[j]);
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
         printf("\n\n");
        }

}
int main()
{
     insert();
     print() ;
}
