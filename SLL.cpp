#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int item;
    node *next;
};
class SLL
{
   private:
       node *start;
   public:    
       SLL();
       SLL(SLL&);
       SLL& operator=(SLL&);
       void InsertAtFirst(int);
       void InsertAtLast(int);
       void InsertAfter(node*,int);
       void DeleteFirst();
       void DeleteLast();
       void DeleteNode(node*);
       void Edit(node*,int);
       node* Search(int);
       bool IsEmpty();
       int Count();
       void PrintList();
       ~SLL();
};
SLL::SLL()
{
    start=NULL;
}
SLL::SLL(SLL &L)
{ 
     node *t;
     t=L.start;
     start=NULL;   
     while(t)
     {
        InsertAtLast(t->item);
        t-t->next; 
     }
}
SLL& SLL::operator=(SLL &L)
{
    node *t;
    t=L.start;
    while(start)
      DeleteFirst();
    while(t)
     {
        InsertAtLast(t->item);
        t-t->next; 
     }
    return *this; 
}
void SLL::InsertAtFirst(int data)
{
   node *n=new node;
   n->item=data;
   n->next=start;
   start=n;
} 
void SLL::InsertAtLast(int data)
{
    node *n=new node,*temp;  
    n->item=data;
    n->next=NULL;
     if(start==NULL)
       start=n;
     else
     {
        temp=start;
        while(temp->next!=NULL)
          temp=temp->next;
        temp->next=n;
     }  
}
void SLL::InsertAfter(node *n,int data)
{
   if(n)
   {  
      node *node;
      node->item=data;
      node->next=n->next;
      n->next=node;
   }
}
void SLL::DeleteFirst()
{
  if(IsEmpty())
     cout<<"List Underflow";
  else 
  {  
    node *temp=start;
    start=start->next;
    delete temp;
  }
}
void SLL::DeleteLast()
{
  try
  {
    if(IsEmpty())
     throw "List Underflow";
    if(start->next==NULL)
      {
        delete start;
        start=NULL;
      }
    else 
     {   
       node *temp=start;
       while(temp->next->next!=NULL)     
       temp=temp->next;
       delete temp->next;
       temp->next=NULL;
     }  
  }
  catch(char *str)
   { cout<<str;}
}
void SLL::DeleteNode(node *n)
{
  if(n)
  {
    if(start==n)
        DeleteFirst();
    else
    {
       node *t=start;
       while(t->next!=n)
         t=t->next;
       t->next=n->next;
       delete n;  
    }    
  }
  else
  cout<<"Invalied item";
}
void SLL::Edit(node *n,int newData)
{
  if(n)
    n->item=newData;
  else
    cout<<"Node Does'nt Exist";  
}
bool SLL::IsEmpty()
{
  if(start==NULL)
     return true;
  return false;   
}
node* SLL::Search(int item)
{
    node *temp;
    temp=start;
    while(temp!=NULL)
    {
        if(temp->item==item)
            return temp;
        temp=temp->next;
    } 
    return NULL;
}
int SLL::Count()
{
   int c=0;
   node *temp=start;
   while(temp!=NULL)
      {
         temp=temp->next;
         c++;
      }
  return c;    
}
void SLL::PrintList()
{
  if(!IsEmpty())
     {
       node *temp=start;
       while(temp!=NULL)
       {
         cout<<temp->item<<" ";
         temp=temp->next;
       }
     }
   else
    cout<<"List Is Empty";  
}
SLL::~SLL()
{
   while(start)
     DeleteFirst();
}
