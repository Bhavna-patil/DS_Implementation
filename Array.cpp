#include<stdlib.h>
#include<iostream>
using namespace std;
template<class X>
class Array
{
  private:
      int capacity;
      int lastIndex;
      X *ptr;
  public:
      Array();
      Array(int a);
      Array(Array<X>&);
      Array& operator=(Array<X>&);
      void creatArray(int);
      void Insert(int,X);
      void Append(X);
      void Delete(int);
      void Edit(int,X);
      X getItem(int);
      bool isEmpty();
      bool isFull();
      int SearchData(X);
      int countItem();
      int getCapacity();
      ~Array();
};
template<class X>
Array<X>::Array()
{
   ptr=NULL;
   capacity=0;
   lastIndex=-1;
}
template<class X>
Array<X>::Array(int c)
{
    capacity=c;
    lastIndex=-1;
    ptr=new X[capacity];
}
template<class X>
Array<X>::Array(Array<X> &A)
{
    capacity=A.capacity;
    lastIndex=A.lastIndex;
    ptr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
      ptr[i]=A.ptr[i];
}
template<class X>
Array<X>& Array<X>::operator=(Array<X> &A)
{
    if(ptr!=NULL)
       delete []ptr;
    capacity=A.capacity;
    lastIndex=A.lastIndex;
    ptr=new X[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
      ptr[i]=A.ptr[i];  
      return *this; 
}
template<class X>
void Array<X>::creatArray(int c)
{
   if(ptr!=NULL)
     delete []ptr;
   capacity=c;
   lastIndex=-1;
   ptr=new X[capacity];
}
template<class X>
void Array<X>::Insert(int index,X data)
{
   if(index<0||index>lastIndex+1)
         cout<<"Invalied Index !!!!!!!!!!";
   if(!isFull())  
      {
         int i;
         for(i=lastIndex+1;i>index;i--)
             ptr[i]=ptr[i-1];  
             ptr[index]=data;
        lastIndex++;      
      } 
   else
     cout<<"Array Overflow ";
}
template<class X>
void Array<X>::Append(X data)
{
    if(isEmpty())
       {
          ptr[lastIndex+1]=data;
          lastIndex++;
       }
    else
     cout<<"Array Overflow";   
}
template<class X>
void Array<X>::Delete(int index)
{
     if(index<0||index>lastIndex)
         cout<<"Invalied Index or Underflow !!!!!!!!!!";
      else   
      {
        int i;
        for(i=index;i<lastIndex;i++) 
           ptr[i]=ptr[i+1];
        lastIndex--;      
      } 
}
template<class X>
void Array<X>::Edit(int index,X data)
{
    if(index<0||index>lastIndex)
         cout<<"Invalied Index !!!!!!!!!!";
      else   
       ptr[index]=data;
}
template<class X>
X Array<X>::getItem(int index)
{
    try
    {
       if(index<0||index>lastIndex)
          throw 1;
          return ptr[index];
    }
    catch(int){cout<<"Invalied Index" ;}
    return -1;
}
template<class X>
int Array<X>::SearchData(X data)
{
   int i;
   for(i=0;i<=lastIndex;i++)
      if(ptr[i]==data)
         return i;
   return -1;      
}
template<class X>
bool Array<X>::isEmpty()
{
    return capacity!=lastIndex+1; 
}
template<class X>
bool Array<X>::isFull()
{
    return capacity==lastIndex+1;  
}
template<class X>
int Array<X>::countItem()
{
    return lastIndex+1;
}
template<class X>
int Array<X>::getCapacity()
{
    return capacity;
}
template<class X>
Array<X>::~Array()
{
    delete []ptr;
}