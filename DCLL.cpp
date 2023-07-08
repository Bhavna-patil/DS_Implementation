#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DCLL
{
    private:
       node *start;
    public: 
       DCLL(); 
       DCLL(DCLL&);
       DCLL& operator=(DCLL&);
       void InsertAtStart(int);
       void InsertAtLast(int);
       void InsertAfter(node*,int); 
       node *Search(int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteNode(node*);
       void PrintLIstItem();
       ~DCLL();
};
DCLL::DCLL()
{
    start=NULL;
}
DCLL::DCLL(DCLL &l)
{
    node *t=l.start;
    if(l.start)
    {
        start=NULL;
        while(t!=l.start->prev)
        {
            InsertAtLast(t->item);
            t=t->next;
        }
        InsertAtLast(t->item);
    }
    else
     start=NULL;
}
DCLL& DCLL::operator=(DCLL &l)
{
    while(start)
       DeleteFirst();
        node *t=l.start;
    if(l.start)
    {
        while(t!=l.start->prev)
        {
            start=NULL;
            InsertAtLast(t->item);
            t=t->next;
        }
        InsertAtLast(t->item);
    }
    else
     start=NULL;
    return *this; 
}
void DCLL::InsertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
       n->prev=n;
       n->next=n;
       start=n; 
    }
   else
   {
      n->prev=start->prev;
      n->next=start;
      start->prev->next=n;
      start->prev=n;
      start=n;
   }
}
void DCLL::InsertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(start==NULL)
    {
       n->prev=n;
       n->next=n;
       start=n; 
    }
    else
    {
       n->prev=start->prev;
       n->next=start;
       start->prev->next=n;
       start->prev=n;
    }
}
void DCLL::InsertAfter(node *t,int data)
{
   if(t)
   {
         node *n=new node;
          n->prev=t; 
          n->item=data;
          n->next=t->next;
          t->next->prev=n;
          t->next=n;  
   }
}
node* DCLL::Search(int data)
{
    node *t=start;
    if(start==NULL)
       return NULL;
    do
    {
      if(t->item==data)
         return t;
       t=t->next;  
    } while(t!=start);
  
    return NULL;
}
void DCLL::DeleteFirst()
{
    node *r;
    if(start)
    {
       if(start->next==start)
          {
            delete start;
            start=NULL;
          }
       else
         {
            r=start;
            start->prev->next=start->next;
            start->next->prev=start->prev;
            start=start->next;
            delete r;
         }  
    }
    else
     cout<<"UNDERFLOW..........";
}
void DCLL::DeleteLast()
{
     node *r;
    if(start)
    {
       if(start->next==start)
          {
            delete start;
            start=NULL;
          }
       else
         {
            r=start->prev;
            r->prev->next=start;
            start->prev=r->prev;
            delete r;
         }  
    }
    else
    cout<<"UNDEFLOW.........";
}
void DCLL::DeleteNode(node *r)
{
    if(r)
    {
        if(r==start)
          DeleteFirst();
        else
        {
            r->prev->next=r->next;
            r->next->prev=r->prev;
            delete r;
        }  
    }
}
void DCLL::PrintLIstItem()
{
    if(start)
    {
        node *t=start;
        while(t!=start->prev)
           {
             cout<<t->item<<" ";
             t=t->next;
           }
         cout<<t->item;  
    }
    else
    cout<<"UNDERFLOW.......";
}
DCLL::~DCLL()
{
    while(start)
      DeleteFirst();
}

 