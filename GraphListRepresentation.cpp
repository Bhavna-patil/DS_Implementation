#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int vertex;
    node *next;
};
// Adjacency List

class AdjList
{
    protected:
      node *start;
      int vertex;
    public:
      AdjList();
      AdjList(AdjList&);
      AdjList& operator=(AdjList&);
      void addVertex(int);
      void setVertex(int);
      void DeleteFirst();  
      node* get_start();
      node* search(int);
      int getVertex(node*);
      void printList(); 
      bool is_empty();
      ~AdjList();
};
AdjList::AdjList()
{
    start=NULL;
    vertex=0;
}
AdjList::AdjList(AdjList &l)
{
    start=NULL;
    vertex=l.vertex;
    node *t=l.start;
    while(t)
    {
      addVertex(t->vertex);
      t=t->next;
    }
}
AdjList& AdjList::operator=(AdjList &l)
{
    while(start)
      DeleteFirst();
    node *t=l.start;
    while(t)
    {
      addVertex(t->vertex);
      t=t->next;
    }
    return *this;
}
int AdjList::getVertex(node *n)
{
   return n->vertex;
}
void AdjList::setVertex(int v)
{
   vertex=v;
}
node* AdjList::get_start()
{
   return start;
}
bool AdjList::is_empty()
{
  return start==NULL;
}
void AdjList::DeleteFirst()
{ 
   node *t=start;
   if(start)
   {
     start=start->next;
     delete t;
   }
}
void AdjList::printList()
{
   node *t=start;
   while(t)
   {
      cout<<t->vertex<<" ";
      t=t->next;
   }
}
void AdjList::addVertex(int v)
{
    node *n=new node;
    n->vertex=v;
    n->next=start;
    start=n;
}
node* AdjList::search(int v)
{
   node *t=start;
   while(t)
   {
    if(t->vertex==v)
      return t;
      t=t->next;
   }
  return NULL;
}
AdjList::~AdjList()
{
    while(start)
      DeleteFirst();
}
// Graph

class Graph
{
   private:
    int v_count;
    AdjList *arr;
  public:
    Graph();
    Graph(Graph&);
    Graph& operator=(Graph &G);
    void creatGraph(int);
    void addEdge(int,int);
    void printGraph();
    void PrintAdjVertex(int);
    void BFS(int);
    void DFS(int);
    ~Graph();
};
Graph::Graph()
{
    v_count=0;
    arr=NULL;
}
Graph::Graph(Graph &G)
{
    v_count=G.v_count;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
      arr[i]=G.arr[i];
}
Graph& Graph::operator=(Graph &G)
{
  if(arr!=NULL)
  { 
    node *t;
    for(int i=0;i<v_count;i++)
    {
       t=arr[i].get_start();
        while(t)
        arr[i].DeleteFirst();
    }
     delete []arr; 
  }
    v_count=G.v_count;
    arr=new AdjList[v_count];
    for(int i=0;i<v_count;i++)
      arr[i]=G.arr[i];
}
void Graph::creatGraph(int vno)
{
    int u,v;
    v_count=vno;
    arr = new AdjList[v_count]; 
    cout<<"Enter vertex Number:-"; 
    for(int i=0;i<v_count;i++)
       {
          arr[i].setVertex(i);
          cout<<"\n Enter the no of adjacency node of v"<<i<<":-";
          cin>>u;
          for(int j=0;j<u;j++)
          {
            cout<<"\nEnter vertex number";
            cin>>v;
            arr[i].addVertex(v);
          }
       }
}  
void Graph::addEdge(int u,int v)
{
    if((u>=0&&u<v_count)&&(v>=0&&v<v_count))
    {
        if(!arr[u].search(v))
        arr[u].addVertex(v);
        if(!arr[v].search(u))
        arr[v].addVertex(u);
    }
}
void Graph::printGraph()
{
   int i;
   for(i=0;i<v_count;i++)
   {
      cout<<"Adjacency Vertex of V"<<i<<":-";
      arr[i].printList();
      cout<<endl;
   }
}
void Graph::PrintAdjVertex(int v)
{
   if(v>=0&&v<v_count)
     arr[v].printList();
}
Graph::~Graph()
{
  node *t;
  for(int i=0;i<v_count;i++)
  {
      t=arr[i].get_start();
      while(t)
        arr[i].DeleteFirst();
  }
   delete []arr;   
}
//Breath first traversal
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
      ~Queue();
      int get_front(){return ptr[front];}
      bool is_empty(){return front==-1;}
};
Queue::Queue(int c)
{
    capacity=c;
    front=-1;
    rear=-1;
    if(c>0)
    ptr=new int[capacity];
    else 
    ptr=NULL;
}
void Queue::Insert(int data)
{
    if(rear==-1)
       front++;
    if(rear==capacity-1)   
       rear=-1;
    ptr[++rear]=data;   
}
void Queue::Delete()
{
    if(rear==front)
        front=rear=-1;
    else if(front==capacity-1)   
        front=0;
    else    
        front++;    
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
     node *t=arr[v].get_start();
      while(t)
      {
         int u;
         u=arr[v].getVertex(t);
         if(mark[u]==false)
         {
            mark[u]=true;
            q.Insert(u);
         }
         t=t->next;   
      }
   }
}
// Depth first Traversal
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
         node *t=arr[v].get_start();
         while(t)
         {
            int u=arr[v].getVertex(t);
            if(mark[u]==false)
            {
               mark[u]=true;
               s.Push(u);
            }
            t=t->next;
         }
      }
}
int main()
{
   Graph g;
   g.creatGraph(5);
   g.addEdge(0,1);
   g.addEdge(0,4);
   g.addEdge(4,3);
   g.addEdge(3,2);
   g.addEdge(4,2);
   g.addEdge(1,4);
   g.addEdge(1,2);
   g.printGraph();
   cout<<endl<<endl;
   g.DFS(3);
   return 0;
}