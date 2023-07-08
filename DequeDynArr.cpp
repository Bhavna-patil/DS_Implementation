
#include<iostream>
#include<stdlib.h>
using namespace std;
#define UNDERFLOW 1
#define OVERFLOW 2
class Deque
{
    private:
       int capacity;
       int front,rear;
       int *ptr;
    protected:
       void doubleArr();
       void halfArr();   
    public:
       Deque(int);
       Deque(Deque&);
       Deque& operator=(Deque&);
       void InsertAtRear(int);
       void InsertAtFront(int);
       void DeleteRear();
       void DeleteFront();
       int get_front();
       int get_rear();
       bool is_empty();
       bool is_full();
       int count();
       int get_capacity();
       void Display();
       ~Deque();   
};
void Deque::doubleArr()
{
    int *temp;
    temp=new int[2*capacity];
    int i=front,k=0;
    while(i!=rear) 
    {
        temp[k]=ptr[i];
        i++,k++;
        if(i==capacity)
          i=0;
    }
    temp[k]=ptr[i];
    delete ptr;
    ptr=temp;
    front=0;
    rear=k;
    capacity=2*capacity;
}
void Deque::halfArr()
{
    int *temp;
    temp=new int[capacity/2];
    int i=front,k=0;
    while(i!=rear) 
    {
        temp[k]=ptr[i];
        i++,k++;
        if(i==capacity)
          i=0;
    }
    temp[k]=ptr[i];
    delete ptr;
    ptr=temp;
    front=0;
    rear=k;
    capacity=capacity/2;
}
Deque::Deque(int c)
{
    capacity=c;
    front=-1;
    rear=-1;
    if(c>0)
     ptr=new int[capacity];
    else
     ptr=NULL;
}
Deque::Deque(Deque &q)
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
Deque& Deque::operator=(Deque &q)
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
void Deque::InsertAtRear(int data)
{
    if(is_full())
      doubleArr();
    if(rear==-1)
      front=0;
    if(rear==capacity-1)  
      rear=-1;
    ptr[++rear]=data;  
}
void Deque::InsertAtFront(int data)
{
    if(is_full())
      doubleArr();
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
void Deque::DeleteFront()
{
    if(is_empty())
      throw UNDERFLOW ;
    if(front==rear)  
       front=rear=-1;
    else if(front==capacity-1)
       front=0;
    else
       front++;   
    if(count()<=capacity/2&&capacity>1)   
      halfArr();
}
void Deque::DeleteRear()
{
    if(is_empty())
      throw UNDERFLOW ;
    if(front==rear)  
       front=rear=-1;
    else if(rear==0)
        rear=capacity-1;
    else
        --rear;   
    if(count()<=capacity/2&&capacity>1)     
       halfArr();
}
bool Deque::is_empty()
{
    return rear==-1;
}
bool Deque::is_full()
{
    return (front==0&&rear==capacity-1||rear==front-1);
}
int Deque::get_front()
{
    if(is_empty())
       throw UNDERFLOW ;
    return ptr[front];   
}
int Deque::get_rear()
{
    if(is_empty())
       throw UNDERFLOW ;
    return ptr[rear];   
}
int Deque::count()
{
    if(is_empty())
      return 0;
    if(front==rear)
      return 1;
    if(rear>front)
      return rear-front+1;
    return capacity-front+rear+1;
}
Deque::~Deque()
{
    delete ptr;
}
void Deque::Display()
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
int Deque::get_capacity()
{
    return capacity;
}
int main()
{
    Deque d(1);
    d.InsertAtFront(1);
    d.InsertAtRear(2);
    d.InsertAtFront(0);
    d.InsertAtRear(3);
    d.DeleteFront();
    d.DeleteFront();
    cout<<d.get_capacity()<<endl;
    d.Display();
    return 0;
}