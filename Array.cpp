#include<stdlib.h>
#include<iostream>
using namespace std;
class Array
{
  private:
      int capacity;
      int lastIndex;
      int *ptr;
  public:
      Array();
      Array(int a);
      Array(Array&);
      Array& operator=(Array&);
      void creatArray(int);
      void Insert(int,int);
      void Append(int);
      void Delete(int);
      void Edit(int,int);
      int getItem(int);
      bool isEmpty();
      bool isFull();
      int SearchData(int);
      int countItem();
      int getCapacity();
      ~Array();
};
Array::Array()
{
   ptr=NULL;
   capacity=0;
   lastIndex=-1;
}
Array::Array(int c)
{
    capacity=c;
    lastIndex=-1;
    ptr=new int[capacity];
}
Array::Array(Array &A)
{
    capacity=A.capacity;
    lastIndex=A.lastIndex;
    ptr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
      ptr[i]=A.ptr[i];
}
Array& Array::operator=(Array &A)
{
    if(ptr!=NULL)
       delete []ptr;
    capacity=A.capacity;
    lastIndex=A.lastIndex;
    ptr=new int[capacity];
    int i;
    for(i=0;i<=lastIndex;i++)
      ptr[i]=A.ptr[i];  
      return *this; 
}
void Array::creatArray(int c)
{
   if(ptr!=NULL)
     delete []ptr;
   capacity=c;
   lastIndex=-1;
   ptr=new int[capacity];
}
void Array::Insert(int index,int data)
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
void Array::Append(int data)
{
    if(isEmpty())
       {
          ptr[lastIndex+1]=data;
          lastIndex++;
       }
    else
     cout<<"Array Overflow";   
}
void Array::Delete(int index)
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
void Array::Edit(int index,int data)
{
    if(index<0||index>lastIndex)
         cout<<"Invalied Index !!!!!!!!!!";
      else   
       ptr[index]=data;
}
int Array::getItem(int index)
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
int Array::SearchData(int data)
{
   int i;
   for(i=0;i<=lastIndex;i++)
      if(ptr[i]==data)
         return i;
   return -1;      
}
bool Array::isEmpty()
{
    return capacity!=lastIndex+1; 
}
bool Array::isFull()
{
    return capacity==lastIndex+1;  
}
int Array::countItem()
{
    return lastIndex+1;
}
int Array::getCapacity()
{
    return capacity;
}
Array::~Array()
{
    delete []ptr;
}