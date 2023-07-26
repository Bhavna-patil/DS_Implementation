#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class student
{
    private:
      int rollNo;
      string name;
      string stream;
      int year;
    public:
      student(){ }
      student(int r,string n,string s,int year):rollNo(r),name(n),stream(s),year(year)  
      {}
      void showStudent()
      {
        cout<<rollNo<<" "<<name<<" "<<stream<<" "<<year<<endl;
      }
      int getRollno()
      {
        return rollNo;
      }
};
struct node
{
    student item;
    node *next;
};

class HashTable
{
    private:
       int capacity;
       node **ht;
       int hashFunction(int);
       void hashing(student);
    public:
       HashTable(int);   
       void insert(student);
       node* search(int);
};

HashTable::HashTable(int cap)
{
   capacity=cap;
   ht=new node*[capacity];
     for(int i=0;i<capacity;i++)
       ht[i]=NULL;
}
void HashTable::hashing(student s)
{
   int key;
   node *n=new node;
   n->item=s;
   n->next=NULL;
   key=s.getRollno();
   if(ht[key]==NULL)
       ht[key]=n;
   else
   {
      node *temp;
      temp=ht[key]->next;
      while(temp)
         temp=temp->next;
      temp=n;   
   } 
}
int HashTable::hashFunction(int key)
{
    return key;
}
void HashTable::insert(student s)
{
   hashing(s);
}
node* HashTable::search(int key)
{
    int k=hashFunction(key);
    try
    {
       if(ht[k]==NULL||key>=capacity)
          throw 1;
       else
         return ht[k];   
    }
    catch(int)
    {
       cout<<"Data is Not found";
    }
    
}
int main()
{
    student s(1,"Bhavna","cse",2020);
    student s1(4,"isha","cse",2020);
    student s2(3,"koyna","cse",2020);
    student s3(2,"vaish","cse",2020);
    HashTable ht(10);
    ht.insert(s);
    ht.insert(s1);
    ht.insert(s2);
    ht.insert(s3);
    node *temp;
    temp=ht.search(13);
    student st;
    st=temp->item;
    st.showStudent();
    return 0;
}