#include<iostream>
#include<stdio.h>
using namespace std;
#define EMPTY_TREE 1
#define DATA_NOT_FOUND 2
template<class X>
struct node
{
    node<X> *left;
    X item;
    node<X> *right;
};
template<class X>
class BST
{
    private:
       node<x> *root; 
       void recPreorder(node<X>*);
       void recInorder(node<X>*);
       void recPostorder(node<X>*); 
       void CopyInorder(BST<X>&,node<X>*); 
    protected:
       node<X>* creatNode(X);   
    public:
       BST();  
       BST(BST<X>&);
       BST<X>& operator=(BST<X>&);
       bool is_empty(); 
       void Insert(X);
       void preorder_traversal();
       void postorder_traversal();
       void inorder_traversal();
       void Delete(X);
       node<X>* search(X);
       ~BST();
};
template<class X>
BST<X>::BST()
{
    root=NULL;
}
template<class X>
void BST<X>::CopyInorder(BST<X> &b,node<X> *root)
{
    if(root)
    {
        CopyInorder(b,root->left);
        b.Insert(root->item);
        CopyInorder(b,root->right);
    }
}
template<class X>
BST<X>::BST(BST<X> &bst)
{
  root=NULL;
  if(bst.root)
    bst.CopyInorder(*this,bst.root);
}
template<class X>
BST<X>& BST<X>::operator=(BST<X> &bst)
{
  while(root)
    Delete(root->item);
  if(bst.root)
    bst.CopyInorder(*this,bst.root);
   return *this; 
}
template<class X>
bool BST<X>::is_empty()
{
    return root==NULL;
} 
template<class X>
node<X>* BST<X>::creatNode(X data)
{
    node<X> *n=new node;
    n->left=NULL;
    n->item=data;
    n->right=NULL;
    return n;
}
template<class X>
void BST<X>::Insert(X data)
{
    node<X> *t;
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
template<class X>
void BST<X>::recPostorder(node<X> *root)
{
    if(root)
    {
        recPostorder(root->left);
        recPostorder(root->right);
        cout<<root->item; 
    } 
}
template<class X>
void BST<X>::postorder_traversal()
{
    recPostorder(root);
}
template<class X>
void BST<X>::recPreorder(node<X> *root)
{
    if(root)
    {
        cout<<root->item; 
        recPreorder(root->left);
        recPreorder(root->right);
    } 
}
template<class X>
void BST<X>::preorder_traversal()
{
    recPreorder(root);
}
template<class X>
void BST<X>::recInorder(node<X> *root)
{
    if(root)
    {
        recInorder(root->left);
        cout<<root->item; 
        recInorder(root->right);
    } 
}
template<class X>
void BST<X>::inorder_traversal()
{
    recInorder(root);
}
template<class X>
void BST<X>::Delete(X data)
{
    node<X> *ptr,*prtptr;
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
           node<X> *suc,*prtsuc;
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
           node<X> *suc,*prtsuc;
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
template<class X>
node<X>* BST<X>::search(X data)
{
   node<X> *t=root;
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
template<class X>
BST<X>::~BST()
{
    while(root)
      Delete(root->item);
}
