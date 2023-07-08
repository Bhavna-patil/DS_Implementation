#include<iostream>
#define Stack_Underflow =1
using namespace std;
struct node
{
    int item;
    node *next;
};
class Stack
{
    private:
       node *top;
    public:
       Stack();
       Stack(Stack&);
       Stack& operator=(Stack&);
       void Push(int);
       int Peek();
       void Pop();
       bool IsEmpty();
       void ReverseStack();
       void DisplayStack();
       ~Stack();
};
Stack::Stack()
{
    top=NULL;
}
void Stack::ReverseStack()
{
    Stack s1;
    while(top)
      {
         s1.Push(Peek());
         Pop();
      }
    top=s1.top;
    s1.top=NULL;
}
Stack::Stack(Stack &s)
{
    node *t;
    if(s.IsEmpty())
       top=NULL;
    else
    { 
        top=NULL;
        t=s.top;
        while(t)
        {
            Push(t->item);
            t=t->next;
        }
    }   
   ReverseStack(); 
}
Stack& Stack::operator=(Stack &s)
{
    while(top)
      Pop();
    node *t;
    if(!s.IsEmpty())
    { 
        t=s.top;
        while(t)
        {
            Push(t->item);
            t=t->next;
        }
    }   
   ReverseStack();  
   return *this; 
}
void Stack::Push(int data)
{
    node *n=new node;
    n->item=data; 
    n->next=top;
    top=n;   
}
bool Stack::IsEmpty()
{
    return top==NULL;
}
int Stack::Peek()
{
    if(top==NULL)
       throw "Stack_UnderFlow";
    return top->item;   
}
void Stack::Pop()
{
    if(top==NULL)
      cout<<"Stack Underflow";
    else
    {
        node *r=top;
        top=top->next;
        delete r;
    }  
}
Stack::~Stack()
{
    while(top)
     Pop();
}
void Stack::DisplayStack()
{
   node *t=top;
   while(t)
   {
     cout<<t->item<<" ";
     t=t->next;
   }
}
int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.DisplayStack();
    s.ReverseStack();
     Stack s1;
     s1=s;
    cout<<endl;
    s1.DisplayStack();
    return 0;
}