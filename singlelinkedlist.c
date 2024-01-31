#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>
typedef struct student
{
   int rollno  ;
   char name[20] ;
   struct student *next ;
}stu;
void menu()
{
   printf("a:add p:print e:exit\n");
}
stu *add(stu *p)
{
   stu *newnode ; /* pointer means it is capable to stotr address of sturucture means capable to fetch the data ,;,;if int * then it capable to fetch integer pointer ;*/
   newnode = malloc(sizeof(stu)*1) ;
   if(newnode==NULL)
   {
     printf("memory not allocated");
   }
   else
   {
     printf("enter your rollno\n") ;
     scanf("%d" , &newnode->rollno) ; /* why & when dereference to rollno now its is like a variable write now to same &var_name ok*/
     printf("enter student name\n") ;
     scanf("%s",newnode->name); /* here no need to of & becuase string name itself an address .*/
     newnode->next = p ;
     p = newnode ; // contains an address of structure .
   }
   return p ; /* why we return the adress because *p is new pointer contains adrees of headptr so new addresss save at p if we back whitout return then pointer p got collaspe and that created memory become memory leakage and we cant get any changes further so before collasping we collect the updaed adress in headptr.
   */

}
void print(stu *p)
{
     while(p)
     {
         printf("%d\t" , p->rollno) ;
         printf("%s\n" , p->name);
         p = p->next ;
     }
}
stu *delete(stu *p)
{
    int rollno ;
    printf("enter the rollno to delete\n");
    scanf("%d",&rollno);
    if(p==NULL)
    {
       printf("empty\n") ;
       return p ;
    }
    else if(p->rollno==rollno)
    {
       stu *temp = p ;
       p = p->next ;
       free(temp) ;
       return p ;
    }
    else
    {
       stu *temp , *prev ;
       prev = p ;
       temp = p->next ;
       while(temp!=NULL && temp->rollno!=rollno)
       {
            prev = temp ;
            /* yaha do chiz hai ek to temp jo point kara hai or temp->next jo uske next ko point karega dont get confused ok . */
           temp = temp->next ;
          /* here we want break the loop as our rollno found wont want to continue it ok and second one if data have only one node so definetly p->next pointing to null only so should terminate ok . */
       }
       if(temp==NULL)
       {
          /* null in two cases 1 as last node and second 1 element node next contains null in means only one node is present ......*/
               printf("data not founded\n");
       }
       else
       {
           prev->next = temp->next ;
           free(temp) ;
           return p  ;
       }
    }
                                                                                                                                                                                                                                                                                                                                                     1,17          Top
}
int main()
{
   stu *headptr = NULL ;
   char choise ;
   while(1)
   {
       menu();
       printf("enter your choise\n");
       __fpurge(stdin);
       scanf("%c",&choise);

       switch(choise)
       {
         case 'a' : headptr = add(headptr) ;
                    break ;
         case 'p' : print(headptr) ;
                    break ;
         case 'e' : return 0 ;
         case 'd' : headptr = delete(headptr) ;
                    break ;
         default : printf("invlaid\n");
       }
   }

}
