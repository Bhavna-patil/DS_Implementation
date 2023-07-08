#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
    int item;
    node *next;
};
class CLL
{
    private:
       node *last;
    public:
      CLL();
      CLL(CLL&);
      CLL& operator=(CLL&);   
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
      ~CLL();
};
CLL::CLL()
{
    last=NULL;
}
CLL::CLL(CLL &L)
{
   if(L.last)
   {
      node *t=L.last->next;
      last=NULL;
      while(t!=L.last)
      {
         InsertAtLast(t->item);
         t=t->next;
      }
      InsertAtLast(L.last->item);
   }
   else
     last=NULL;
}
CLL& CLL::operator=(CLL &L)
{
  while(last)
     DeleteFirst();
  if(L.last)   
  {
     node *t=L.last->next;
     last=NULL;
     while(t!=L.last)
     {
        InsertAtLast(t->item);
        t=t->next;
     }
     InsertAtLast(L.last->item);
  }
  else
    last=NULL;
  return *this;  
}
void CLL::InsertAtStart(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        n->next=n;
        last=n;
    }
    else
    {
        n->next=last->next;
        last->next=n;
    }
}
void CLL::InsertAtLast(int data)
{
    node *n=new node;
    n->item=data;
    if(last==NULL)
    {
        last=n;
        n->next=last;
    }
    else
    {
      n->next=last->next;
      last->next=n;
      last=n;
    }
}
void CLL::InsertAfter(node *n1,int data)
{
    if(n1)
    {
        node *n=new node;
        n->item=data;
        n->next=n1->next;
        n1->next=n;
        if(n1==last)
         last=n;
    }
}
node* CLL::Search(int item)
{
  if(last)
  {
     node *t=last;
     if(last->item==item)
     return last;
     else   
      {
         t=t->next;
         while(t!=last)
          {
            if(t->item==item)
            return t;
            t=t->next;
          }
      }
  }
   return NULL;
}
void CLL::DeleteFirst()
{
    try
    {
       if(last==NULL) 
          throw "UNDERFLOW";
       else if(last->next==last)
        {
           delete last;
           last=NULL;
        }
      else
       {
         node *t=last->next;
         last->next=t->next;
         delete t;
       }
    }
    catch(char *str)
     {cout<<str;}
}
void CLL::Edit(node *n,int data)
{
  if(n)
   n->item=data;
}
int CLL::CountLIstItem()
{
  int c=0;
  if(last==NULL)
    return c;
  else
    {
      node *t=last->next;
      while(t!=last)
        {
          c++;
          t=t->next;
        }
    }  
  return c++;  
}
void CLL::DeleteLast()
{
    try
    {
       if(last==NULL) 
          throw "UNDERFLOW";
       else if(last->next==last)
        {
           delete last;
           last=NULL;
        }
      else
      {
        node *t=last->next;
        while(t->next!=last)
          t=t->next;
        t->next=last->next;
        delete last;
        last=t;
      }
    }
    catch(char *str)
     {
        cout<<str;
     }
}
void CLL::DeleteNode(node *n)
{
    if(n)
    {
        if(last->next==last)
        {
            delete last;
            last=NULL;
        }
        else if(n==last->next)
        {
           last->next=n->next;
           delete n;
        }
        else
        {
           node *t=last->next;
           while(t->next!=n)  
             t=t->next;
           t->next=n->next;
           if(n==last)
            last=t;
           delete n; 
        }
    }
}
void CLL::ShowLIstItem()
{
  if(last)
  {
     node *t=last->next;
     while(t!=last)
     {
       cout<<t->item<<" ";
       t=t->next;
     }
     cout<<last->item<<" ";  
  }
  else
  cout<<"List is empty";
}
CLL::~CLL()
{
   if(last)
    DeleteFirst();
}

int main()
{
  CLL c1 ;
  c1.InsertAtLast(1);
  c1.InsertAtLast(2);
  c1.InsertAtLast(3);
  c1.InsertAtStart(0);
  c1.InsertAfter(c1.Search(3),4);
  c1.DeleteFirst();
  c1.DeleteLast();
  c1.DeleteNode(c1.Search(3));
  cout<<endl;
  CLL c2=c1;
  c2.ShowLIstItem();
  return 0;
}