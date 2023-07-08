#include<iostream>
using namespace std;
class DynArrStack
{
   private:
      int capacity;
      int top;
      int *ptr;
   protected:
      void doubleArr();
      void halfArr();      
   public:
      DynArrStack();
      DynArrStack(int);
      DynArrStack(DynArrStack&);
      DynArrStack& operator=(DynArrStack&);
      void Push(int);
      void Pop();
      int Peek();
      bool IsFull();
      bool IsEmpty();
      ~DynArrStack(); 
};
DynArrStack::DynArrStack()
{
    ptr=NULL;
    capacity=0;
    top=-1;
}
DynArrStack::DynArrStack(int c)
{
    capacity=c;
    top=-1;
    ptr=new int[capacity];
}
DynArrStack::DynArrStack(DynArrStack &s)
{
    capacity=s.capacity;
    top=s.top;
    int i;
    ptr=new int[capacity];
    for(i=0;i<=top;i++)
      ptr[i]=s.ptr[i];
}
DynArrStack& DynArrStack::operator=(DynArrStack &s)
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
void DynArrStack::doubleArr()
{
    int *t,i;
    t=new int[capacity*2];
    for(i=0;i<=top;i++)
       t[i]=ptr[i];
    delete ptr;
    ptr=t;
    capacity=2*capacity;   
}
void DynArrStack::halfArr()
{
    int *t,i;
    t=new int[capacity/2];
    for(i=0;i<=top;i++)
      t[i]=ptr[i];
    delete ptr;
    ptr=t;
    capacity=capacity/2;  
}
void DynArrStack::Push(int data)
{
    if(capacity==0)
       throw 1;
    if(IsFull())
      doubleArr();
    ptr[++top]=data;  
}
void DynArrStack::Pop()
{
    if(IsEmpty())
      cout<<"Underflow";
    else
       top--;
    if(top+1<capacity/2&&capacity>1) 
      halfArr();    
}
int DynArrStack::Peek()
{
    if(IsEmpty())
      throw 1;
    else
      return ptr[top];  
}
bool DynArrStack::IsEmpty()
{
    return top==-1;
}
bool DynArrStack::IsFull()
{
    return top==capacity-1;
}
DynArrStack::~DynArrStack()
{
    delete []ptr;
}