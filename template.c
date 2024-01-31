#include<iostream>
using namespace std ;
template<class type>
type sum(type a ,  type b)
{
        return a+b ;
}
int main()
{
     cout<<sum(2,4);
     cout<<sum(2.5,3.5) ;
     return 0 ;
}  // use when logic is same but function are in multiple to reduce it one template is use here 
