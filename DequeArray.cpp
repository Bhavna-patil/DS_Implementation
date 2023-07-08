#include<iostream>
#include<stdlib.h>
using namespace std;
#define UNDERFLOW 1
#define OVERFLOW 2
class DequeArr
{
    private:
       int capacity;
       int front,rear;
       int *ptr;
    public:
       DequeArr(int);
       DequeArr(DequeArr&);
       DequeArr& operator=(DequeArr&);
       void InsertAtRear(int);
       void InsertAtFront(int);
       void DeleteRear();
       void DeleteFront();
       int get_front();
       int get_rear();
       bool is_empty();
       bool is_full();
       int count();
       void Display();
       ~DequeArr();   
};
DequeArr::DequeArr(int c)
{
    capacity=c;
    front=-1;
    rear=-1;
    if(c>0)
     ptr=new int[capacity];
    else
     ptr=NULL;
}
DequeArr::DequeArr(DequeArr &q)
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
DequeArr& DequeArr::operator=(DequeArr &q)
{
    if(ptr)
      delete []ptr;
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
void DequeArr::InsertAtRear(int data)
{
    if(is_full())
      throw OVERFLOW ;
    if(rear==-1)
      front=0;
    if(rear==capacity-1)  
      rear=-1;
    ptr[++rear]=data;  
}
void DequeArr::InsertAtFront(int data)
{
    if(is_full())
     throw OVERFLOW ;
    if(front==-1) 
    {
        front=rear=0;
        ptr[front]=data;
    }
    else if(front==0)
    {
        int i;
        for(i=rear;i>=front;i--)
          ptr[i+1]=ptr[i];
        ptr[front]=data;  
        rear++;  
    }
    else
    ptr[--front]=data;
}
void DequeArr::DeleteFront()
{
    if(is_empty())
      throw UNDERFLOW ;
    if(front==rear)  
       front=rear=-1;
    else if(front==capacity-1)
       front=0;
    else
       front++;   
}
void DequeArr::DeleteRear()
{
    if(is_empty())
      throw UNDERFLOW ;
    if(front==rear)  
       front=rear=-1;
    else if(rear==0)
        rear=capacity-1;
    else
        --rear;    
}
bool DequeArr::is_empty()
{
    return rear==-1;
}
bool DequeArr::is_full()
{
    return (front==0&&rear==capacity-1||rear==front-1);
}
int DequeArr::get_front()
{
    if(is_empty())
       throw UNDERFLOW ;
    return ptr[front];   
}
int DequeArr::get_rear()
{
    if(is_empty())
       throw UNDERFLOW ;
    return ptr[rear];   
}
int DequeArr::count()
{
    if(is_empty())
      return 0;
    if(front==rear)
      return 1;
    if(rear>front)
      return rear-front+1;
    return capacity-front+rear+1;
}
DequeArr::~DequeArr()
{
    delete ptr;
}
void DequeArr::Display()
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
    else 
      throw UNDERFLOW;
}