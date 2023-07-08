#include<iostream>
#include<stdlib.h>
using namespace std;
class ArrStack 
{
    private:
       int capacity;
       int top;
       int *ptr;
    public:
       ArrStack();
       ArrStack(int);
       ArrStack(ArrStack&);
       ArrStack& operator=(ArrStack&);
       void creatStack(int);
       void PUSH(int);
       void POP();
       int Peek();
       bool IsEmpty();
       bool IsFull(); 
       ~ArrStack();  
};
ArrStack::ArrStack()
{
    capacity=0;
    top=-1;
    ptr=NULL;
}
ArrStack::ArrStack(int c)
{
    capacity=c;
    top=-1;
    ptr=new int[capacity];
}
void ArrStack::creatStack(int c)
{
    if(ptr!=NULL)
       delete []ptr;
    capacity=c;
    top=-1;
    ptr=new int[capacity];
}
ArrStack::ArrStack(ArrStack &s)
{
   capacity=s.capacity;
   top=s.top;
   ptr=new int[capacity];
   int i;
   for(i=0;i<=top;i++)
    ptr[i]=s.ptr[i];
}
ArrStack& ArrStack::operator=(ArrStack &s)
{
    if(ptr)
     delete []ptr;
    capacity=s.capacity;
    top=s.top;
    ptr=new int[capacity];
    int i; 
    for(i=0;i<=top;i++)
      ptr[i]=s.ptr[i];
      return *this;
}
void ArrStack::PUSH(int data)
{
    if(IsFull())
       cout<<"Stack  Overflow";
    else    
       ptr[++top]=data;
}
void ArrStack::POP()
{
    if(IsEmpty())
      cout<<"Stack  Undeflow";
    else
      top--;  
}
int ArrStack::Peek()
{
    try
    { 
        if(IsEmpty())
          throw "Undeflow";
        else
          return ptr[top];  
    }
    catch(string s)
    {
       cout<<s;
    }
}
bool ArrStack::IsEmpty()
{
    return top==-1;
}
bool ArrStack::IsFull()
{
    return top==capacity-1;
}
ArrStack::~ArrStack()
{
    delete []ptr;
}

