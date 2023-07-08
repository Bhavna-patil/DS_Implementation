#include<iostream>
#include<stdlib.h>
using namespace std;
#define UNDERFLOW 1
struct node
{
    node *prev;
    int item;
    node *next;
};
class DequeList
{
    private:
       node *front,*rear;
    public:
       DequeList();
       DequeList(DequeList&);
       DequeList& operator=(DequeList&);
       void InsertAtRear(int);
       void InsertAtFront(int);
       void DeleteRear();
       void DeleteFront();
       int get_front();
       int get_rear();
       int count();
       void Display();
       ~DequeList();   
};
DequeList::DequeList()
{
    front=rear=NULL;
}
DequeList::DequeList(DequeList &d)
{
   node *t=d.front;
   if(d.front==NULL)
      front=rear=NULL;
   else
   {
      front=rear=NULL;
      while(t)
      {
         InsertAtRear(t->item);
         t=t->next;
      }
   }   
}
DequeList& DequeList::operator=(DequeList &d)
{
   while(front)
     DeleteFront();
   node *t=d.front;
      while(t)
      {
         InsertAtRear(t->item);
         t=t->next;
      }
   return *this; 
}
void DequeList::InsertAtFront(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=front;
      if(front==NULL)
         front=rear=n;
    else  
    {   
      front->prev=n; 
      front=n;
    }
}
void DequeList::InsertAtRear(int data)
{
   node *n=new node;
   n->prev=rear;
   n->item=data;
   n->next=NULL;
   if(rear==NULL)
      front=rear=n;
   else
      {
        rear->next=n;
        rear=n;
      }   
}
void DequeList::DeleteFront()
{
    if(front==NULL)
       throw UNDERFLOW ;
    if(front==rear)   
       {
          delete front;
          front=rear=NULL;
       }
    else
    {
        front=front->next;
        delete front->prev;
        front->prev=NULL;
    }   
}
void DequeList::DeleteRear()
{
    if(rear==NULL)
      throw UNDERFLOW ;
    if(front==rear)  
    {
        delete rear;
        front=rear=NULL;
    }
    else
    {
        rear=rear->prev;
        delete rear->next;
        rear->next=NULL;
    }
}
int DequeList::get_front()
{
    if(front==NULL)
      throw UNDERFLOW ;
    return front->item;  
}
int DequeList::get_rear()
{
    if(front==NULL)
      throw UNDERFLOW ;
    return rear->item;  
}
int DequeList::count()
{
    if(front==NULL)
     return 0;
    if(front==rear) 
     return 1;
    node *t=front;
    int c=0;
    while(t!=rear) 
    {
       c++;
       t=t->next;
    }
    return ++c;
}
void DequeList::Display()
{
    if(front==NULL)
      cout<<"UNDERFLOW";
    else
    {
        node *t=front;
        while(t!=rear)
        {
            cout<<t->item<<" ";
            t=t->next;
        }
         cout<<t->item;
    }  
}
DequeList::~DequeList()
{
    while(front)
      DeleteFront();
}
int main()
{
    DequeList d1;
    d1.InsertAtFront(1);
    d1.InsertAtRear(2);
    d1.InsertAtRear(3);
    d1.InsertAtFront(0);
    DequeList d2=d1;
    cout<<d2.count()<<endl;
    d2.Display();
    return 0;
}
