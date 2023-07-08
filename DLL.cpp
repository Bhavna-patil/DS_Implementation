#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    node *prev;
    int item;
    node *next;
};
class DLL
{
   private:
      node *start;
   public:
      DLL();
      DLL(DLL&);
      DLL& operator=(DLL&);   
      void InsertAtStart(int);
      void InsertAtLast(int);
      void InsertAfter(node*,int);
      node* Search(int);
      void DeleteFirst();
      void DeleteLast();
      void DeleteNode(node*);
      void Edit(node*,int);
      int CountLIstItem();
      void ShowLIstItem();
      ~DLL();
};
DLL::DLL() {start=NULL;}
DLL::DLL(DLL &L)
{
   node *t=L.start;
   if(L.start)
   {
      while(t->next!=NULL)
         t=t->next;
      while(t)   
      {
         InsertAtStart(t->item);
         t=t->prev;
      }
   }
   else
   start=NULL;
}
DLL& DLL::operator=(DLL &L)
{
    while(start)
        DeleteFirst();
    node *t=L.start;
    if(L.start)
   {
      while(t->next!=NULL)
         t=t->next;
      while(t)   
      {
         InsertAtStart(t->item);
         t=t->prev;
      }
   }
   else
   start=NULL;
   return *this;
}
void DLL::InsertAtStart(int data)
{
    node *n=new node;
    n->prev=NULL;
    n->item=data;
    n->next=start;
    if(start)
    start->prev=n;
    start=n;
}
void DLL::InsertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    n->next=NULL;
    if(!start)
       {
          n->prev=NULL;
          start=n;
       }
    else
    {
        node *t=start;
        while(t->next)
           t=t->next;
        n->prev=t; 
        t->next=n;  
    }   
}
void DLL::InsertAfter(node *n1,int data)
{
    if(n1)
    {
        node *n=new node;
        n->prev=n1;
        n->item=data;
        n->next=n1->next;
        if(n1->next!=NULL)
            n1->next->prev=n;
        n1->next=n;
    }
}
node* DLL::Search(int item)
{
    node *t=start;
    while(t)
    {
        if(t->item==item)
           return t;
        t=t->next;   
    }
    return NULL;
}
void DLL::DeleteFirst()
{
    if(start)
    {
       node *t;
       t=start->next;
       delete start;
       start=t;
       start->prev=NULL;
    }
    else
      cout<<"List UnderFlow";
}
void DLL::DeleteLast()
{
    if(start)
    {
        if(start->next=NULL)
        {
            delete start;
            start=NULL;
        }
        else
        {
            node *t=start;
            while(t->next)
               t=t->next;  
            t->prev->next=NULL;
           delete t;
        }    
    }
    else
      cout<<"List UNderflow";
}
void DLL::DeleteNode(node *n)
{
   if(n)
   {
        if(n==start)
           DeleteFirst();
       else
       { 
         n->prev->next=n->next;
         if(n->next!=NULL)
         n->next->prev=n->prev;
         delete n;
       }
   }
   else
     cout<<"List Underflow";
}
void DLL::Edit(node *n,int data)
{
    if(n)
      n->item=data;
}
int DLL::CountLIstItem()
{
    node *t=start;
    int c=0;
    while(t)
    {
        c++;
        t=t->next;
    }
    return c;
}
void DLL::ShowLIstItem()
{
   node *t=start;
   while(t)
   {
     cout<<t->item<<" ";
     t=t->next;
   }
}
DLL::~DLL()
{
    while(start)
      DeleteFirst();
}