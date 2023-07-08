#include<iostream>
#include<stdlib.h>
#define Queue_overflow 1
#define Queue_underflow 2
#define INVALID_CAPACITY_STATE 3
using namespace std;
class QueueArr
{
    private:
        int capacity;
        int front;
        int rear;
        int *ptr;
    public:
        QueueArr(int);
        QueueArr(QueueArr&);
        QueueArr& operator=(QueueArr&);
        void Insert(int);
        void Delete();
        int get_Front();
        int get_Rear();  
        bool is_full();
        bool is_empty();
        int Count();
        void Display();
        ~QueueArr();  
};
QueueArr::QueueArr(int c)
{
    capacity=c;
    front=-1;
    rear=-1;
    if(c>0)
    ptr=new int[capacity];
    else 
    ptr=NULL;
}
QueueArr::QueueArr(QueueArr &q)
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
QueueArr& QueueArr::operator=(QueueArr &q)
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
void QueueArr::Insert(int data)
{
    if(capacity<=0)
       throw INVALID_CAPACITY_STATE ;
    if(is_full())
       throw Queue_overflow ;
    if(rear==-1)
       front++;
    if(rear==capacity-1)   
       rear=-1;
    ptr[++rear]=data;   
}
void QueueArr::Delete()
{
    if(is_empty())
       throw Queue_underflow ;
    if(rear==front)
        front=rear=-1;
    else if(front==capacity-1)   
        front=0;
    else    
        front++;    
}
bool QueueArr::is_full()
{
    if(front==0&&rear==capacity-1||rear==front-1)
       return true;
    return false;          
}
bool QueueArr::is_empty()
{
   return(front==-1&&rear==-1); 
}
int QueueArr::get_Front()
{
    if(is_empty())
      throw Queue_underflow;
    return ptr[front];
}
int QueueArr::get_Rear()
{
    if(is_empty())
      throw Queue_underflow;
    return ptr[rear];
}
int QueueArr::Count()
{
    if(rear==-1)
      return 0;
    if(front==rear)  
      return 1;
    if(rear>front)  
      return rear-front+1;
    else
      return capacity-front+rear+1;  
}
QueueArr::~QueueArr()
{
    delete ptr;
}
void QueueArr::Display()
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
