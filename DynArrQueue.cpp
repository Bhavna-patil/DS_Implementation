#include<iostream>
#include<stdlib.h>
#define Queue_Underflow 1
using namespace std;
class DynArrQ
{
    private:
       int capacity;
       int front;
       int rear;
       int *ptr;
    protected:
       void doubleArr();
       void halfArr();
    public:
       DynArrQ(int);
       DynArrQ(DynArrQ&);
       DynArrQ& operator=(DynArrQ&);
       void Insert(int);
       void Delete();
       bool is_full();
       bool is_empty();
       int count();
       int get_front();
       int get_rear();
       void Display();
       ~DynArrQ();     
};
void DynArrQ::doubleArr()
{
    int *temp,i=front,j=0;
    temp=new int[2*capacity];
    while(i!=rear)  
      {
         temp[j]=ptr[i];
         j++;i++;
         if(i==capacity)
           i=0;
      }
    temp[j]=ptr[i];
   delete ptr;
   ptr=temp;
   capacity=2*capacity;
   front=0;
   rear=j;   
}
void DynArrQ::halfArr()
{
    int *temp,i=front,j=0;
    temp=new int[capacity/2];
    while(i!=rear)  
      {
         temp[j]=ptr[i];
         j++;i++;
         if(i==capacity)
           i=0;
      }
    temp[j]=ptr[i];
   delete ptr;
   ptr=temp;
   capacity=capacity/2;
   front=0;
   rear=j; 
}
DynArrQ::DynArrQ(int c)
{
    capacity=c;
    front=-1;
    rear=-1;
    ptr=new int[capacity];
}
DynArrQ::DynArrQ(DynArrQ &q)
{
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int[capacity];
    int i=front;
    if(!q.is_empty())
    {
        while(i!=rear)
        {
            ptr[i]=q.ptr[i];
            i++;
            if(i==capacity)
              i=0;
        }
        ptr[i]=q.ptr[i];
    }
}
DynArrQ& DynArrQ::operator=(DynArrQ &q)
{
    delete ptr;
    capacity=q.capacity;
    front=q.front;
    rear=q.rear;
    ptr=new int[capacity];
    int i=front;
    if(!q.is_empty())
    {
        while(i!=rear)
        {
            ptr[i]=q.ptr[i];
            i++;
            if(i==capacity)
              i=0;
        }
        ptr[i]=q.ptr[i];
    }
    return *this;
}
void DynArrQ::Insert(int data)
{
    if(is_full())
      doubleArr();
    if(rear==-1)  
      front++;
    if(rear==capacity-1)
       rear=-1;
    ptr[++rear]=data;
}
void DynArrQ::Delete()
{
    if(is_empty())
       throw Queue_Underflow ;
    if(rear==front)
      {
         front=-1;
         rear=-1;
      }
    else if(front==capacity-1)   
        front=0;
    else    
    front++;
    if(capacity/2>=count()&&capacity>1)      
      halfArr();
}
bool DynArrQ::is_empty()
{
    return front==-1&&rear==-1;
}
bool DynArrQ::is_full()
{
    return (front==0&&rear==capacity-1||rear==front-1);
}
int DynArrQ::get_front()
{
    return ptr[front];
}
int DynArrQ::get_rear()
{
    return ptr[rear];
}
int DynArrQ::count()
{
    int c=0,i=front;
    if(is_empty())
      return c;
    while(i!=rear)  
    {
        c++;
        i++;
        if(i==capacity)
        i=0;
    }
    return ++c;
}
DynArrQ::~DynArrQ()
{
    delete ptr;
}
void DynArrQ::Display()
{
    int i=front;
    if(!is_empty())
    {
        while(i!=rear)
        {
            cout<<ptr[i]<<" ";
            i++;
            if(i==capacity)
              i=0;
        }
        cout<<ptr[i];
    }
}
