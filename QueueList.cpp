#include<iostream>
#include<stdlib.h>
using namespace std;
#define UNDERFLOW 1;
struct node
{
    int item;
    node *next;
};
class Qlist
{
    private:
       node *rear;
       node *front;
    public:
       Qlist();
       Qlist(Qlist&);
       Qlist& operator=(Qlist&);
       void Insert(int);
       void Delete();
       bool is_empty(); 
       int get_front();
       int get_rear();
       int count();  
       ~Qlist();
};
Qlist::Qlist()
{
    rear=NULL;
    front=NULL;
}
Qlist::Qlist(Qlist &q)
{
    node *t=q.front;
    front=NULL;
    rear=NULL;
    while(t!=NULL)
      {
        Insert(t->item);
        t=t->next;
      }
}
Qlist& Qlist::operator=(Qlist &q)
{
    while(front)
      Delete();
    node *t=q.front;
    while(t!=NULL)
      {
         Insert(t->item);
         t=t->next;
      }
    return *this;
}
void Qlist::Insert(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(is_empty())
      front=n;
    else 
    rear->next=n;
    rear=n;
}
void Qlist::Delete()
{
    node *r=front;
    if(!is_empty())
    {
        if(front==rear)
          rear=NULL;
        front=front->next;
        delete r;
    }
}
bool Qlist::is_empty()
{
    return rear==NULL;
}
int Qlist::get_front()
{
    if(rear==NULL)
       throw UNDERFLOW ;
    return front->item;
}
int Qlist::get_rear()
{
    if(rear==NULL)
       throw UNDERFLOW ;
    return rear->item;
}
int Qlist::count()
{
    node *t=front;
    int c=0;
    while(t)   
    {
        c++;
        t=t->next;
    }
    return c;
}
Qlist::~Qlist()
{
    while(front)
      Delete();
}