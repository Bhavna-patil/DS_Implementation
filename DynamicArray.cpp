#include<stdlib.h>
#include<iostream>
using namespace std;

class Array
{
    private:
       int capacity;
       int lastIndex;
       int *ptr;
    protected:
       void setCapacity(int);
       void setPointer(int *);
       void setLastIndex(int);    
    public:
       Array();   
       Array(int);
       Array(Array&);
       Array& operator=(Array&);
       void CreatArray(int);
       virtual void Insert(int,int);
       virtual void Append(int);
       void Edit(int,int);
       virtual void Delete(int);
       int GetData(int);
       int Count();
       int getCapacity();
       int SearchData(int);
       int* getPointer();
       int getLastIndex();
       bool isEmpty();
       bool isFull();
       ~Array();
};
void Array::setPointer(int *temp) { delete []ptr; ptr=temp; }
void Array::setLastIndex(int c) {lastIndex=c;  }
Array::Array()
{
    capacity=0;
    lastIndex=-1;
    ptr=NULL;
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
void Array::CreatArray(int c)
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
int Array::GetData(int index)
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
bool Array::isEmpty()  { return lastIndex==-1; }
bool Array::isFull()  { return capacity==lastIndex+1; }
int Array::Count()  { return lastIndex+1; }
int Array::getCapacity()  { return capacity; }
int Array::getLastIndex() {  return lastIndex;}
void Array::setCapacity(int c) { capacity=c; }
int* Array::getPointer()  {  return ptr; }
Array::~Array() { delete []ptr; }

class DynamicArray:public Array
{
   protected:
        void doubleArray();
        void halfArray();
   public:
        DynamicArray();   
        DynamicArray(DynamicArray&);
        DynamicArray& operator=(DynamicArray&);
        void Insert(int,int);
        void Append(int);
        void Delete(int);    
        ~DynamicArray();
};
DynamicArray::DynamicArray():Array()
{
   setCapacity(0);
   setLastIndex(-1);
   setPointer(NULL);
}
DynamicArray::DynamicArray(DynamicArray &a)
{
   int *p,*q=a.getPointer(),i;
   setCapacity(a.getCapacity());
   setLastIndex(a.getLastIndex());
   setPointer(new int[getCapacity()]);
   p=getPointer();
   for(i=0;i<=getLastIndex();i++)
      p[i]=q[i];  
}
DynamicArray& DynamicArray::operator=(DynamicArray &a)
{
   int *p=getPointer(),*q=a.getPointer(),i;
   if(p!=NULL)
      delete []p;
   setCapacity(a.getCapacity());
   setLastIndex(a.getLastIndex());
   setPointer(new int[getCapacity()]);
   p=getPointer();
   for(i=0;i<=getLastIndex();i++)
      p[i]=q[i];
   return *this;   
}
void DynamicArray::doubleArray()
  {
     int *temp,i,*p;
     p=getPointer();
     temp=new int[getCapacity()*2];
     for(i=0;i<Count();i++)
       temp[i]=p[i];
     setPointer(temp);  
     setCapacity(2*getCapacity());  
  }
void DynamicArray::halfArray()  
{
   int *temp,i,*p;
   p=getPointer();
   temp=new int[getCapacity()/2];
   for(i=0;i<Count();i++)
     temp[i]=p[i];
   setPointer(temp);
   setCapacity(getCapacity()/2);
}
void DynamicArray::Insert(int index,int data)
{
   int *p;
   p=getPointer();
   if(isFull())
   {
       doubleArray();
       setCapacity(2*getCapacity());
       p=getPointer();
   }
   try 
   {   
      if(index<0||index>getLastIndex()+1)  
        throw 1;
   }catch(int){cout<<"Invalied Index";} 
   int i;
   for(i=getLastIndex()+1;i<index;i--)
        p[i]=p[i-1];
        p[index]=data;
   setLastIndex(getLastIndex()+1);
}
void DynamicArray::Append(int data)
{ 
   int *p=getPointer();
   if(isFull())
   {
       doubleArray();
       p=getPointer();
   }
   p[getLastIndex()+1]=data;
   setLastIndex(getLastIndex()+1);
}
void DynamicArray::Delete(int index)
{
   int *p;
   p=getPointer();
   try
   {
       if(isEmpty())
          throw 1;
       else if(index<0||index>getLastIndex())   
          throw 2;
       else
       {
          int i;
          for(i=index;i<getLastIndex();i++)
            p[i]=p[i+1];
          setLastIndex(getLastIndex()-1);   
       }
   }
   catch(int a)
   {
      if(a==1)
      cout<<"Array Underflow";
      else
      cout<<"Invalied Index";
   }
   if(getCapacity()>1 && getLastIndex()+1<=getCapacity()/2)
      halfArray();
}
DynamicArray::~DynamicArray() {delete []getPointer();}

int main()
{
   DynamicArray a;
   int i;
   a.CreatArray(6);
   a.Insert(0,90);
   a.Append(10);
   a.Append(20);
   a.Append(30);
   a.Append(40);
   a.Delete(3);
   for(i=0;i<a.Count();i++)
     cout<<a.GetData(i)<<" ";
   cout<<endl<<a.SearchData(168);
   return 0;  
}