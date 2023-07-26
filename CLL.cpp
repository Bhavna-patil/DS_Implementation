#include<stdlib.h>
#include<iostream>
using namespace std;
template<class X>
struct node
{
    X item;
    node<X> *next;
};
template<class X>
class CLL
{
    private:
       node<X> *last;
    public:
      CLL();
      CLL(CLL<X>&);
      CLL<X>& operator=(CLL<X>&);   
      void InsertAtStart(X);
      void InsertAtLast(X);
      void InsertAfter(node<X>*,X);
      node<X>* Search(X);
      void DeleteFirst();
      void DeleteLast();
      void DeleteNode(node<X>*);
      void Edit(node<X>*,X);
      int CountLIstItem();
      void ShowLIstItem();
      ~CLL();
};
template<class X>
CLL<X>::CLL()
{
    last=NULL;
}
template<class X>
CLL<X>::CLL(CLL<X> &L)
{
   if(L.last)
   {
      node<X> *t=L.last->next;
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
template<class X>
CLL<X>& CLL<X>::operator=(CLL<X> &L)
{
  while(last)
     DeleteFirst();
  if(L.last)   
  {
     node<X> *t=L.last->next;
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
template<class X>
void CLL<X>::InsertAtStart(X data)
{
    node<X> *n=new node<X>;
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
template<class X>
void CLL<X>::InsertAtLast(X data)
{
    node<X> *n=new node<X>;
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
template<class X>
void CLL<X>::InsertAfter(node<X> *n1,X data)
{
    if(n1)
    {
        node<X> *n=new node<X>;
        n->item=data;
        n->next=n1->next;
        n1->next=n;
        if(n1==last)
         last=n;
    }
}
template<class X>
node<X>* CLL<X>::Search(X item)
{
  if(last)
  {
     node<X> *t=last;
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
template<class X>
void CLL<X>::DeleteFirst()
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
         node<X> *t=last->next;
         last->next=t->next;
         delete t;
       }
    }
    catch(char *str)
     {cout<<str;}
}
template<class X>
void CLL<X>::Edit(node<X> *n,X data)
{
  if(n)
   n->item=data;
}
template<class X>
int CLL<X>::CountLIstItem()
{
  int c=0;
  if(last==NULL)
    return c;
  else
    {
      node<X> *t=last->next;
      while(t!=last)
        {
          c++;
          t=t->next;
        }
    }  
  return c++;  
}
template<class X>
void CLL<X>::DeleteLast()
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
        node<X> *t=last->next;
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
template<class X>
void CLL<X>::DeleteNode(node<X> *n)
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
           node<X> *t=last->next;
           while(t->next!=n)  
             t=t->next;
           t->next=n->next;
           if(n==last)
            last=t;
           delete n; 
        }
    }
}
template<class X>
void CLL<X>::ShowLIstItem()
{
  if(last)
  {
     node<X> *t=last->next;
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
template<class X>
CLL<X>::~CLL()
{
   if(last)
    DeleteFirst();
}

int main()
{
  CLL<int> c1 ;
  c1.InsertAtLast(1);
  c1.InsertAtLast(2);
  c1.InsertAtLast(3);
  c1.InsertAtStart(0);
  c1.InsertAfter(c1.Search(3),4);
  c1.ShowLIstItem();
  c1.DeleteFirst();
  c1.DeleteLast();
  c1.DeleteNode(c1.Search(3));
  cout<<endl;
  CLL<int> c2=c1;
  c2.ShowLIstItem();
  return 0;
}