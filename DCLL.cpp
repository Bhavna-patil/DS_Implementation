#include<stdlib.h>
#include<iostream>
using namespace std;
template<class X>
struct node
{
    node<X> *prev;
    X item;
    node<X> *next;
};
template<class X>
class DCLL
{
    private:
       node<X> *start;
    public: 
       DCLL(); 
       DCLL(DCLL<X>&);
       DCLL<X>& operator=(DCLL<X>&);
       void InsertAtStart(X);
       void InsertAtLast(X);
       void InsertAfter(node<X>*,X); 
       node<X>* Search(X);
       void DeleteFirst();
       void DeleteLast();
       void DeleteNode(node<X>*);
       void PrintLIstItem();
       ~DCLL();
};
template<class X>
DCLL<X>::DCLL()
{
    start=NULL;
}
template<class X>
DCLL<X>::DCLL(DCLL<X> &l)
{
    node<X> *t=l.start;
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
template<class X>
DCLL<X>& DCLL<X>::operator=(DCLL<X> &l)
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
template<class X>
void DCLL<X>::InsertAtStart(X data)
{
    node<X> *n=new node<X>;
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
template<class X>
void DCLL<X>::InsertAtLast(X data)
{
    node<X> *n=new node<X>;
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
template<class X>
void DCLL<X>::InsertAfter(node<X> *t,X data)
{
   if(t)
   {
         node<X> *n=new node<X>;
          n->prev=t; 
          n->item=data;
          n->next=t->next;
          t->next->prev=n;
          t->next=n;  
   }
}
template<class X>
node<X>* DCLL<X>::Search(X data)
{
    node<X> *t=start;
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
template<class X>
void DCLL<X>::DeleteFirst()
{
    node<X> *r;
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
template<class X>
void DCLL<X>::DeleteLast()
{
     node<X>*r;
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
template<class X>
void DCLL<X>::DeleteNode(node<X> *r)
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
template<class X>
void DCLL<X>::PrintLIstItem()
{
    if(start)
    {
        node<X> *t=start;
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
template<class X>
DCLL<X>::~DCLL()
{
    while(start)
      DeleteFirst();
}

 