#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//Define a function tamplate which takes two arguments of same types and return the greater value
template<typename x>
x Greater(x data1,x data2)
{
    if(data1>data2)
      return data1;
    return data2;  
}
//print values of an arry of any type
template<typename X>
void print(X arr[],int size)
{
    for(int i=0;i<size;i++)
      cout<<arr[i];
}
//Template to sort an element of An array
template<typename x>
int Quick(x arr[],int left,int right)
{
   int t,loc=left;
   while(left<right)
   {
      while(left<right && arr[loc]<=arr[right])
         right--;
      if(left==right)   
        break;
      swap(arr,loc,right);
      loc=right;
      while(left<right && arr[left]<=arr[loc])
        left++;
      if(left==right)  
        break;
      swap(arr,loc,left) ; 
      loc=left;
   }
  return loc;
}
template<typename x>
void sort(x arr[],int size)
{
   int i,j,loc;
   stack<int,vector<int>>low;
   stack<int,vector<int>>high;
   low.push(l);
   high.push(h);
   while(!low.empty())
   {
      i=low.top();
      j=high.top();
      loc=Quick(arr,i,j);
      low.pop();
      high.pop();
      if(loc > i+1)
      {
         low.push(i);
         high.push(loc-1);
      }
      if(loc < j-1)
      {
         low.push(loc+1);
         high.push(j);
      }
   }
}