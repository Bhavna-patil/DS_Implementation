#include<stdlib.h>
#include<iostream>
using namespace std;
template<class X>
class DynArray
{
  private:
      int capacity;
      int lastIndex;
      X *ptr;
  protected:
      void DoubleArr();
      void HalfArr();    
  public:
      DynArray();
      DynArray(int a);
      DynArray(DynArray<X>&);
      DynArray& operator=(DynArray<X>&);
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
      ~DynArray();
};
template<class X>
void DynArray<X>::DoubleArr()
{
   capacity=2*capacity;
   X *temp=new X[capacity];
    for(int i=0;i<=lastIndex();i++)
      temp[i]=ptr[i];
   delete []ptr;
   ptr=temp;   
}
template<class X>
void DynArray<X>::HalfArr()
{
   capacity=capacity/2;
   X *temp=new X[capacity];
    for(int i=0;i<=lastIndex();i++)
      temp[i]=ptr[i];
   delete []ptr;
   ptr=temp;   
}
template<class X>
DynArray<X>::DynArray()
{
   ptr=NULL;
   capacity=0;
   lastIndex=-1;
}
template<class X>
DynArray<X>::DynArray(int c)
{
    capacity=c;
    lastIndex=-1;
    ptr=new X[capacity];
}
template<class X>
DynArray<X>::DynArray(DynArray<X> &A)
{
    capacity=A.capacity;
    lastIndex=A.lastIndex;
    ptr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
      ptr[i]=A.ptr[i];
}
template<class X>
DynArray<X>& DynArray<X>::operator=(DynArray<X> &A)
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
void DynArray<X>::creatArray(int c)
{
   if(ptr!=NULL)
     delete []ptr;
   capacity=c;
   lastIndex=-1;
   ptr=new X[capacity];
}
template<class X>
void DynArray<X>::Insert(int index,X data)
{
   if(index<0||index>lastIndex+1)
         cout<<"Invalied Index !!!!!!!!!!";
   else 
     {
         if(isFull())
            DoubleArr();
         int i;
         for(i=lastIndex+1;i>index;i--)
             ptr[i]=ptr[i-1];  
             ptr[index]=data;
        lastIndex++; 
     }     
}
template<class X>
void DynArray<X>::Append(X data)
{
    if(isFull())
       DoubleArr()
    ptr[lastIndex+1]=data;
    lastIndex++;
}
template<class X>
void DynArray<X>::Delete(int index)
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
      if(lastIndex < capacity/2 && capacity>1)
        HalfArr();
}
template<class X>
void DynArray<X>::Edit(int index,X data)
{
    if(index<0||index>lastIndex)
         cout<<"Invalied Index !!!!!!!!!!";
      else   
       ptr[index]=data;
}
template<class X>
X DynArray<X>::getItem(int index)
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
int DynArray<X>::SearchData(X data)
{
   int i;
   for(i=0;i<=lastIndex;i++)
      if(ptr[i]==data)
         return i;
   return -1;      
}
template<class X>
bool DynArray<X>::isEmpty()
{
    return capacity!=lastIndex+1; 
}
template<class X>
bool DynArray<X>::isFull()
{
    return capacity==lastIndex+1;  
}
template<class X>
int DynArray<X>::countItem()
{
    return lastIndex+1;
}
template<class X>
int DynArray<X>::getCapacity()
{
    return capacity;
}
template<class X>
DynArray<X>::~DynArray()
{
    delete []ptr;
}