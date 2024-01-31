#include<iostream>
using namespace std ;
template<class type1 , class type2>
double sum(type1 a ,  type2 b)
{
        return a+b ;
}
int main()
{
     cout<<sum(10,12.3)<<endl ;
     cout<<sum('a' , 10)<<endl ;
     cout<<sum(12.3,3)<<endl ;
     return 0 ;
}
// return type is double for correct op
// make it type one and type 2 and see the changes in op
// type1 and type2 type depends on each function call parameters its get changes everytime as parameter type changes
                    
