#include<iostream>
using namespace std;
#define OVERFLOW 1
#define UNDERFLOW 2
class Heap
{
    private:
     int capacity;
     int lastIndex;
     int *ptr;
    public:
     Heap(int);
     Heap(Heap&);
     Heap& operator=(Heap&);  
     void Insert(int);
     void Delete();
     int peek();
     void PrintHeap();
     ~Heap();
};
Heap::Heap(int c)
{
    ptr=new int[c];
    capacity=c;
    lastIndex=-1;
}
Heap::Heap(Heap &t)
{
    capacity=t.capacity;
    lastIndex=t.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
      ptr[i]=t.ptr[i];
}
Heap& Heap::operator=(Heap &t)
{
    if(ptr)
      delete []ptr;
    capacity=t.capacity;
    lastIndex=t.lastIndex;
    ptr=new int[capacity];
    for(int i=0;i<=lastIndex;i++)
      ptr[i]=t.ptr[i];
      return *this;
}
int Heap::peek()
{
  if(lastIndex==-1)
    throw UNDERFLOW ;
  return ptr[0];
}
void Heap::Insert(int data)
{
    if(lastIndex==capacity-1)
      throw OVERFLOW;
    //Insert by considering atleat one property of heap that it should bi almost cmplt BT
    ptr[++lastIndex]=data;
    if(lastIndex>0)
    {
       int prtIndex,nodeIndex=lastIndex;
       prtIndex=(nodeIndex-1)/2;
       while(ptr[prtIndex]<ptr[nodeIndex])
       {
          int t=ptr[prtIndex];
          ptr[prtIndex]=ptr[nodeIndex];
          ptr[nodeIndex]=t;
          nodeIndex=prtIndex;
          prtIndex=(nodeIndex-1)/2;
       }
    }
}
void Heap::Delete() //Heap sort If we store the deleted element at lastIndex+1
{
    if(lastIndex==-1)
       throw UNDERFLOW ;
       int k=ptr[0];
    ptr[0]=ptr[lastIndex];
    lastIndex--;
    int l=1,r=2,root=0;
    if(lastIndex>0)
    {
       while(r<=lastIndex && (ptr[root]<ptr[l]||ptr[root]<ptr[r]))
        {
           int Index,t;;
           Index=ptr[l] > ptr[r] ? l : r;
           t=ptr[Index];
           ptr[Index]=ptr[root];
           ptr[root]=t;
           root=Index;
           l=2*root+1;
           r=2*root+2;
        }
        if(ptr[root]<ptr[l]&& l<=lastIndex)
        {
           int t=ptr[root];
           ptr[root]=ptr[l];
           ptr[l]=t;
        }
    }
    ptr[lastIndex+1]=k;
}
void Heap::PrintHeap()
{
  for(int i=0 ;i<lastIndex ;i++)
    cout<<ptr[i]<<" ";
}
Heap::~Heap()
{
  delete []ptr;
}

// HEAP SORT
void HeapSort(int arr[],int size)
{
   Heap h(size);
   //Construct max heap;
   
    for(int i=0 ;i<size ;i++)
       h.Insert(arr[i]);

    //Delete Elemet from Heap
    for(int i=size-1 ;i>=0 ;i--)
    {
       arr[i]=h.peek();
       h.Delete();
    }
}
