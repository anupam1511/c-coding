#include<iostream>
using namespace std ;
int sum(int a ,  int b)
{
        return a+b ;
}
double sum(double a , double b)
{
       return a+b ;
}
int main()
{
     cout<<sum(2,4);
     cout<<sum(2.5,3.5) ;
     return 0 ;
}
                  // why not working for float why ;                                                             
                                                                              
