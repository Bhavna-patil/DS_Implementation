#include<iostream>
#include<stdio.h>
#include<math.h>
#define EMPTY_TREE 1
using namespace std;
template<class X>
struct node
{
    node<X> *left;
    X item;
    node<X> *right;
    int height;
};
template<class X>
class AVLTree
{
   private:
     node<X> *root;
   protected:
     void rec_preorder(node<X>*);
     void rec_inorder(node<X>*);
     void rec_postorder(node<X>*);  
     node<X>* leftRotate(node<X>*);
     node<X>* rightRotate(node<X>*);
     node<X>* creatNode(int);
     node<X>* Insertion(node<X>*,X);
     node<X>* Deletion(node<X>*,X);
     void copyInorder(AVLTree<X>&,node<X>*);
   public:
     AVLTree();
     AVLTree(AVLTree<X>&);
     AVLTree& operator=(AVLTree<X>&);
     int getHeight(node<X>*);  
     void Preorder();
     void Inorder();
     void Postorder();
     void Insert(X);
     int getBalanceFactor(node<X>*);
     node<X>* minValueNode(node<X>*);
     void updateAnscestorsHeights(node<X>*,X);
     node<X>* search(X);
     void Delete(X);
     ~AVLTree();
};
template<class X>
AVLTree<X>::AVLTree()
{
    root=NULL;
}
template<class X>
void AVLTree<X>::copyInorder(AVLTree<X> &t,node<X> *root)
{
    if(root)
    {
        copyInorder(t,root->left);
        t.Insert(root->item);
        copyInorder(t,root->right);
    }
}
template<class X>
AVLTree<X>::AVLTree(AVLTree<X> &t)
{
      root=NULL;
      if(t.root!=NULL)
       copyInorder(*this,t.root);
}
template<class X>
AVLTree<X>& AVLTree<X>::operator=(AVLTree<X> &t)
{
    while(t.root)
     Delete(root->item);
    copyInorder(*this,t.root);
    return *this;
}
template<class X>
int AVLTree<X>::getBalanceFactor(node<X> *ptr)
{
    if(ptr==NULL)
      return 0;
    return getHeight(ptr->left)-getHeight(ptr->right);  
}
template<class X>
int AVLTree<X>::getHeight(node<X> *ptr)
{
    if(ptr==NULL)
      return 0;
    return ptr->height;  
}
template<class X>
node<X>* AVLTree<X>::leftRotate(node<X> *A)
{
    node<X> *B=A->right,*LR=B->left;
    B->left=A;
    A->right=LR;
    A->height=max(getHeight(A->left),getHeight(A->right))+1;
    B->height=max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}
template<class X>
node<X>* AVLTree<X>::rightRotate(node<X> *A)
{
    node<X> *B=A->left;
    node<X> *RT=B->right;
    B->right=A;
    A->left=RT;
    A->height=max(getHeight(A->left),getHeight(A->right))+1;
    B->height=max(getHeight(B->left),getHeight(B->right))+1;
    return B;
}
template<class X>
void AVLTree<X>::rec_preorder(node<X> *ptr)
{
    if(ptr)
    {
        cout<<ptr->item;
        rec_preorder(ptr->left);
        rec_preorder(ptr->right);
    }
}
template<class X>
void AVLTree<X>::rec_inorder(node<X> *ptr)
{
    if(ptr)
    {
        rec_inorder(ptr->left);
        cout<<ptr->item<<"("<<getBalanceFactor(ptr)<<")"<<" ";
        rec_inorder(ptr->right);
    }
}
template<class X>
void AVLTree<X>::rec_postorder(node<X> *ptr)
{
    if(ptr)
    {
        rec_postorder(ptr->left);
        rec_postorder(ptr->right);
        cout<<ptr->item;
    }
}
template<class X>
void AVLTree<X>::Preorder()
{
    rec_preorder(root);
}
template<class X>
void AVLTree<X>::Inorder()
{
    rec_inorder(root);
}
template<class X>
void AVLTree<X>::Postorder()
{
    rec_postorder(root);
}
template<class X>
node<X>* AVLTree<X>::creatNode(int data)
{
    node<X> *n=new node<X>;
    n->left=NULL;
    n->item=data;
    n->left=NULL;
    n->height=1;
    return n;
}
template<class X>
node<X>* AVLTree<X>::minValueNode(node<X> *ptr)
{
  node<X> *suc=ptr;
    while(suc->left)
        suc=suc->left;
    return suc;
}
template<class X>
node<X>* AVLTree<X>::Insertion(node<X>* ptr, X data) 
{ 
   node<X> *n;
    if(ptr==NULL)
      {
        n=new node<X>;
        n->left=NULL;
        n->item=data;
        n->right=NULL;
        n->height=1;
        return n;
      }
    if (data < ptr->item) 
        ptr->left = Insertion(ptr->left,data); 
    else if (data > ptr->item) 
        ptr->right = Insertion(ptr->right, data); 
    else // Duplicate values not allowed 
        return ptr; 
  
    /* 2. Update height of this ancestor node */
    ptr->height = 1 + max(getHeight(ptr->left), getHeight(ptr->right)); 
  
    /* 3. Get the balance factor of this 
        ancestor node to check whether 
        this node became unbalanced */
    int balance = getBalanceFactor(ptr); 
  
    // If this node becomes unbalanced,
    // then there are 4 cases 
  
    // Left Left Case 
    if (balance > 1 && data < ptr->left->item) 
        return rightRotate(ptr); 
  
    // Right Right Case 
    if (balance < -1 && data > ptr->right->item) 
        return leftRotate(ptr); 
  
    // Left Right Case 
    if (balance > 1 && data > ptr->left->item) 
    { 
        ptr->left = leftRotate(ptr->left); 
        return rightRotate(ptr); 
    } 
  
    // Right Left Case 
    if (balance < -1 && data < ptr->right->item) 
    { 
        ptr->right = rightRotate(ptr->right); 
        return leftRotate(ptr); 
    } 
  
    /* return the (unchanged) node pointer */
    return ptr; 
} 
template<class X>
void AVLTree<X>::Insert(X data)
{
    root=Insertion(root,data);
}
template<class X>
node<X>* AVLTree<X>::Deletion(node<X>* ptr,X data)
{
    if(ptr==NULL)
      return ptr;
    if(data < ptr->item)
      ptr->left=Deletion(ptr->left,data);
    else if(data > ptr->item)
      ptr->right=Deletion(ptr->right,data);
    else
    {
        if(ptr->left==NULL||ptr->right==NULL)
        {
           node<X> *temp;
           temp=ptr->left?ptr->left:ptr->right;
           if(temp==NULL)//no child
            {
                temp=ptr;
                ptr=NULL;
            }
            else
                *ptr=*temp; //one chiled
            delete temp;
        }
        else //2 child
        {
           node<X> *temp= minValueNode(ptr->right);
           ptr->item=temp->item;
           ptr->right=Deletion(ptr->right,temp->item);
        }
    }
    if(ptr==NULL)//tree hase single node
      return ptr;
    //update height
    ptr->height=1+max(getHeight(ptr->left),getHeight(ptr->right));
    //balance tree
    int balance=getBalanceFactor(ptr);
    if(balance>1)
    {
       if(data > ptr->right->item)//RR case
         return leftRotate(ptr);
       if(data > ptr->left->item) //LL case  
         return rightRotate(ptr);  
       if(data> ptr->left->item)//LR rotation
       {
          ptr->left=leftRotate(ptr->left);
          return rightRotate(ptr);
       }
       if(data < ptr->right->item)//RL rotation
       {
          ptr->right=rightRotate(ptr->right);
          return leftRotate(ptr);
       }
    }
    return ptr; //unchanged node
}
template<class X>
node<X>* AVLTree<X>::search(X data)
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
void AVLTree<X>::Delete(X data)
{
    root=Deletion(root,data);
}
template<class X>
void AVLTree<X>::updateAnscestorsHeights(node<X> *ptr,X data)
{    
    if(data == ptr->item)
        ptr->height=1;
    else
    {
        if(data < ptr->item)
        {
            updateAnscestorsHeights(ptr->left,data);
        }
        else if(data > ptr->item)
        {
            updateAnscestorsHeights(ptr->right,data);
        }
        ptr->height=max(getHeight(ptr->left),getHeight(ptr->right))+1;
    }
}
int max(int a,int b)
{
    return(a>b?a:b);
}
template<class X>
AVLTree<X>::~AVLTree()
{
    while(root)
     Delete(root->item);
}
int main()
{
  AVLTree<int> t;
  t.Insert(1);
  t.Insert(0);
  t.Insert(2);
  t.Insert(3);
  t.Inorder();
  cout<<endl;
  t.Delete(0);
  AVLTree<int> t1=t;
  t1.Inorder();
  return 0;
}