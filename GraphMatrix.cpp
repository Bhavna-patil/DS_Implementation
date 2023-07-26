#include<iostream>
#include<stdio.h>
using namespace std ;
class Graph
{
    private:
       int v_count;
       int e_count;
       int **adj;
    public:
       Graph();
       void creatGraph(int,int);
       void PrintGraphMatrix();  
       void printAdjacency(int); 
       bool is_isolated(int);
       void DFS(int);
       void BFS(int);
       ~Graph();
};
Graph::Graph()
{
    adj=NULL;
}
void Graph::creatGraph(int v,int e)
{
    int u;
    if(adj!=NULL)
       {
           for(int i=0;i<v_count;i++)
              delete []adj[i];
           delete []adj;
        }
    v_count=v;
    e_count=e;
    adj = new int*[v_count];
    for(int i=0;i<v_count;i++)
       adj[i]=new int[v_count];

    for(int i=0;i<v_count;i++)   
       for(int j=0;j<v_count;j++)
        adj[i][j]=0;

    for(int i=1;i<=e_count;i++)    
    {
        cout<<"\nEnter node number connecting edge";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}
void Graph::PrintGraphMatrix()
{
    int i,j;
    for(i=0;i<v_count;i++)
    {
        for(j=0;j<v_count;j++)
         cout<<adj[i][j]<<" ";
       cout<<endl ;  
    }
}
void Graph::printAdjacency(int p)
{
    int i;
    if(p>=0 && p<v_count)
    {
       for(i=0;i<v_count;i++)
          if(adj[p][i]!=0)
             cout<<adj[p][i]<<" ";
    }
}
bool Graph::is_isolated(int p)
{
    int i;
    if(p >=0 && p<v_count)
    {
      for(i=1;i<v_count;i++)
         if(adj[p][i]==1)
           return false;
    }
    return true ;     
}
// Depth First traversal
class stack
{
   private:
     int capacity;
     int top;
     int *ptr;
   public:
     stack(int);  
     stack(stack &);
     stack& operator=(stack&);
     void Push(int);
     void Pop();
     int Peek();
     bool is_empty();
     ~stack();
};
stack::stack(int c)
{
   ptr=NULL;
   capacity=c;
   top=-1;
   if(capacity>0)
    ptr=new int[capacity];
   else
    ptr=NULL; 
}
stack::stack(stack &s)
{
   capacity=s.capacity;
   top=s.top;
   ptr=new int[capacity];
   for(int i=0;i<=s.top;i++)
    ptr[i]=ptr[i];
}
stack& stack::operator=(stack &s)
{
   if(ptr)
     delete []ptr;
   capacity=s.capacity;
   top=s.top;
   ptr=new int[capacity];
   for(int i=0;i<=s.top;i++)
    ptr[i]=ptr[i];
    return *this;
}
void stack::Push(int data)
{
   if(top==capacity-1)
     throw 1;
   ptr[++top]=data;  
}
void stack::Pop()
{
   if(top==-1)
     throw 2;
   --top;  
}
int stack::Peek()
{
   return ptr[top];
}
bool stack::is_empty()
{
  return top==-1;
}
stack::~stack()
{
   delete []ptr;
}
void Graph::DFS(int v)
{
   stack s(v_count);
   bool mark[v_count];
   s.Push(v);
   mark[v]=true;
      while(!s.is_empty())
      {
         v=s.Peek();
         cout<<v<<" ";
         s.Pop();
         for(int i=0;i<v_count;i++)
         {
            if(adj[v][i]!=0)
            {
              int u=adj[v][i];
              if(mark[u]==false)
               {
                 mark[u]=true;
                 s.Push(u);
               }
            }
         }
      }
}
// Breath First traversal
class Queue
{
    private:
     int capacity;
     int front,rear;
     int *ptr;
    public:
      Queue(int);
      void Insert(int);
      void Delete();
      int get_front();
      bool is_empty();
      ~Queue(); 
};
Queue::Queue(int c)
{
  capacity=c;
  front=rear=-1;
  if(capacity>0)
    ptr=new int[capacity];
  else ptr=NULL;  
}
bool Queue::is_empty()
{
    return front==-1;
}
void Queue::Insert(int data)
{
    if(rear==front-1 && front==0&&rear==capacity-1)
       throw 1;
    if(front==-1)   
      front++;
    if(rear==capacity-1)  
      rear=-1;
    ptr[++rear]=data;  
}
void Queue::Delete()
{
    if(front==-1)
      throw 1;
    if(front==rear)  
      front=rear=-1;
    else if(front==capacity-1)  
      front=0;
    else
      front++;  
}
int Queue::get_front()
{
    return ptr[front];
}
Queue::~Queue()
{
    delete []ptr;
}

void Graph::BFS(int v)
{
    Queue q(v_count);
    bool mark[v_count]={0};
    q.Insert(v);
    mark[v]=true;
    while(!q.is_empty())
    {
       v=q.get_front();
       cout<<v<<" ";
       q.Delete();
       for(int i=0;i<v_count;i++)
       {
          if(adj[v][i]!=0)
          {
             int u=adj[v][i];
             if(mark[u]==false)
             {
                mark[u]=true;
                q.Insert(u);
             }
          }
       }
    }
}
Graph::~Graph()
{
    int i;
   for(i=0;i<v_count;i++)
      delete []adj[i];
   delete []adj ;   
}