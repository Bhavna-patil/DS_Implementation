#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2
struct node
{
    node *left;
    int item;
    node *right;
};
class BST
{
    private:
       node *root; 
       void recPreorder(node*);
       void recInorder(node*);
       void recPostorder(node*); 
       void CopyInorder(BST&,node*); 
    protected:
       node* creatNode(int);   
    public:
       BST();  
       BST(BST&);
       BST& operator=(BST&);
       bool is_empty(); 
       void Insert(int);
       void preorder_traversal();
       void postorder_traversal();
       void inorder_traversal();
       void Delete(int);
       node* search(int);
       ~BST();
};
BST::BST()
{
    root=NULL;
}
void BST::CopyInorder(BST &b,node *root)
{
    if(root)
    {
        CopyInorder(b,root->left);
        b.Insert(root->item);
        CopyInorder(b,root->right);
    }
}
BST::BST(BST &bst)
{
  root=NULL;
  if(bst.root)
    bst.CopyInorder(*this,bst.root);
}
BST& BST::operator=(BST &bst)
{
  while(root)
    Delete(root->item);
  if(bst.root)
    bst.CopyInorder(*this,bst.root);
   return *this; 
}
bool BST::is_empty()
{
    return root==NULL;
} 
node* BST::creatNode(int data)
{
    node *n=new node;
    n->left=NULL;
    n->item=data;
    n->right=NULL;
    return n;
}
void BST::Insert(int data)
{
    node *t;
    if(root==NULL)
    {
        root=creatNode(data);
    }
    else
    {
        bool flag=true;
        t=root;
        while(flag)
        {
            if(data==t->item)
              break;
            if(data<t->item) 
            {
                if(t->left==NULL)
                {
                    t->left=creatNode(data);
                    flag=false;
                }
                else
                t=t->left;
            }
            else //for right subtree
            {
                if(t->right==NULL)
                 {
                    t->right=creatNode(data);
                    flag=false;
                 }
                else
                t=t->right; 
            }
        }
    }
    
}
void BST::recPostorder(node *root)
{
    if(root)
    {
        recPostorder(root->left);
        recPostorder(root->right);
        cout<<root->item; 
    } 
}
void BST::postorder_traversal()
{
    recPostorder(root);
}
void BST::recPreorder(node *root)
{
    if(root)
    {
        cout<<root->item; 
        recPreorder(root->left);
        recPreorder(root->right);
    } 
}
void BST::preorder_traversal()
{
    recPreorder(root);
}
void BST::recInorder(node *root)
{
    if(root)
    {
        recInorder(root->left);
        cout<<root->item; 
        recInorder(root->right);
    } 
}
void BST::inorder_traversal()
{
    recInorder(root);
}
void BST::Delete(int data)
{
    node *ptr,*prtptr;
    if(root==NULL)
        throw EMPTY_TREE;
    ptr=root;
    prtptr=NULL;
    while(ptr)    
    {
        if(ptr->item==data)
          break;
        if(data<ptr->item)  
        {
            prtptr=ptr;
            ptr=ptr->left;
        }
        else
        {
            prtptr=ptr;
            ptr=ptr->right;
        }
    }
    if(ptr==NULL)
       throw DATA_NOT_FOUND ;
    if(ptr==root)
    {
        if(ptr->left==NULL&&ptr->right==NULL)//no child
           {
              delete ptr;
              root=NULL;
           }
        else if(ptr->left && ptr->right) //two child  
        {
           node *suc,*prtsuc;
           suc=ptr->right;
           prtsuc=ptr;
           while(suc->left!=NULL)
           {
              prtsuc=suc;
              suc=prtsuc->left;
           }
           ptr->item=suc->item;
             if(suc==prtsuc->left)
                 prtsuc->left=suc->right;
             else
             prtsuc->right=suc->right;
           delete suc;    
        }
        else //1 child
        {
           if(ptr->left)
              root=ptr->left;
           else
              root=ptr->right;
           delete ptr;      
        }
    }
    else
    {
        if(ptr->left==NULL&&ptr->right==NULL)
        {
            if(prtptr->left==ptr)
               prtptr->left=NULL;
            else
               prtptr->right=NULL;
            delete ptr;      
        }
         else if(ptr->left && ptr->right) //two child  
        {
           node *suc,*prtsuc;
           suc=ptr->right;
           prtsuc=ptr;
           while(suc->left!=NULL)
           {
              prtsuc=suc;
              suc=prtsuc->left;
           }
           ptr->item=suc->item;
             if(suc==prtsuc->left)
                 prtsuc->left=suc->right;
             else
             prtsuc->right=suc->right;
           delete suc;    
        }
        else //1 child
        {
           if(ptr==prtptr->left)      
           {
              if(ptr->left)
                prtptr->left=ptr->left;
              else
                prtptr->left=ptr->right;
              delete ptr;     
           }
           else
           {
             if(ptr->left)
               ptr->right=ptr->left;
             else
               ptr->right=ptr->right;
             delete ptr;    
           }
        }
    }
}
node* BST::search(int data)
{
   node *t=root;
   while(t)
   {
      if(t->item==data)
         return t;
      if(t->item<data)   
         t=t->right;
      else
         t=t->left;   
   }
   return NULL;
}
BST::~BST()
{
    while(root)
      Delete(root->item);
}
