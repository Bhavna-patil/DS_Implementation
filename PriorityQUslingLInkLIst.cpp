#include<iostream>
#include<stdlib.h>
using namespace std;
#define UNDERFLOW 1
struct node
{
    int priority;
    int item;
    node *next;
};
class PriorityQueue
{
    private:
       node *start;
    public:
       PriorityQueue();
       PriorityQueue(PriorityQueue&);
       PriorityQueue& operator=(PriorityQueue&);
       void Insert(int,int);
       void Delete();
       int get_front();
       int get_rear();
       int get_higest_priority();
       int count();
       void Display();
       ~PriorityQueue();
};
PriorityQueue::PriorityQueue()
{
    start=NULL;
}
PriorityQueue::PriorityQueue(PriorityQueue &d)//less expansive if we use DLL;
{
    if(d.start==NULL)
       start=NULL;
    else
    {
        start=NULL;
        node *t=d.start;
        while(t!=NULL)
        {
            Insert(t->priority,t->item);
            t=t->next;
        }
    }   
}
PriorityQueue& PriorityQueue::operator=(PriorityQueue &d)
{
    while(start)
     Delete();
    node *t=d.start;
    while(t!=NULL)
      {
        Insert(t->priority,t->item);
        t=t->next;
      }
}
void PriorityQueue::Insert(int p,int data)
{
    node *n=new node;
    n->priority=p;
    n->item=data;
    if(start==NULL||start->priority<p)
    {
        n->next=start;
        start=n;
    }
    else
    {
         node *t=start;
              while(t->next!=NULL)  
            {
               if(t->next->priority<p)
                  break;
                t=t->next;
            }
           n->next=t->next;
           t->next=n;
    }
    
}
void PriorityQueue::Delete()
{
    if(start==NULL)
       throw UNDERFLOW ;
    node *r=start;
     start=start->next;
     delete r;
}
int PriorityQueue::get_front()
{
    if(start==NULL)
       throw UNDERFLOW ;
    return start->item;   
}
int PriorityQueue::get_rear()
{
    if(start==NULL)
       throw UNDERFLOW ;
    node *t=start;
    while(t->next!=NULL)
       t=t->next;
    return t->item;   
}
int PriorityQueue::get_higest_priority()
{
    if(start)
      return start->priority;
}
int PriorityQueue::count()
{
    if(start==NULL)
      return 0;
    node *t=start;
    int c=0;
        while(t->next!=NULL)
        {
            c++;
            t=t->next;
        }  
    return ++c;    
}
PriorityQueue::~PriorityQueue()
{
    while(start)
     Delete();
}
void PriorityQueue::Display()
{
    if(start==NULL)
      throw UNDERFLOW ;
     node *t=start;
        while(t->next!=NULL)
        {
            cout<<t->item<<" ";
            t=t->next;
        }
      cout<<t->item;  
}
