#include<stdio.h>
#include<stdlib.h>
struct tree //Tree structure
{
  int key, height;
  struct tree *left, *right;
};
typedef struct tree Tree;
int height(Tree *root) //Height calculation for node
{ 
  if(root==NULL) 
    return 0; 
  return root->height; 
} 
int max(int a, int b) //Utility function for maximum of 2 integers
{ 
  return (a>b)?a:b; 
}
Tree *gettree() 
{ 
  return (Tree*)malloc(sizeof(Tree)); 
}
Tree *rotateright(Tree *root) //Right rotation
{ 
  Tree *x=root->left; 
  Tree *y=x->right; 
  x->right=root; 
  root->left=y;  
  root->height=max(height(root->left),height(root->right))+1; 
  x->height = max(height(x->left), height(x->right))+1; 
  return x; 
}  
Tree *rotateleft(Tree *root) //Left rotation
{ 
  Tree *x=root->right; 
  Tree *y=x->left; 
  x->left=root; 
  root->right=y; 
  root->height=max(height(root->left),height(root->right))+1; 
  x->height=max(height(x->left),height(x->right))+1; 
  return x; 
}
int balfac(Tree *root) //Balance factor computation
{ 
  if(root==NULL) 
    return 0; 
  return height(root->left)-height(root->right); 
}
Tree* insert(Tree* root, int val) //Insert in AVL Tree
{ 
  if(root==NULL) //Empty initially
  {
    root=gettree();
    root->key=val; 
    root->left=root->right=NULL;  
    root->height = 1;  
    return root;
  }
  if (val<root->key) 
    root->left=insert(root->left,val); 
  else if(val>root->key) 
    root->right=insert(root->right,val); 
  else 
    return root; 
  root->height=1+max(height(root->left),height(root->right)); //Added child, so increase heights by 1
  int balance=balfac(root);
  if(balance>1 && val<root->left->key) //Imbalance, Left-Left case
    return rotateright(root); 
  if(balance<-1 && val>root->right->key) //Imbalance, Right-Right case
    return rotateleft(root); 
  if(balance>1 && val>root->left->key) //Imbalance, Left-Right case
  { 
    root->left=rotateleft(root->left); 
    return rotateright(root); 
  } 
  if(balance<-1 && val<root->right->key) //Imbalance, Right-Left case
  { 
    root->right=rotateright(root->right); 
    return rotateleft(root); 
  }  
  return root; 
}
void pre_order(Tree *root) //Preorder traversal
{
  printf("%d ",root->key);
  if(root->left!=NULL)
    pre_order(root->left);
  if(root->right!=NULL)
    pre_order(root->right);
}
void in_order(Tree *root) //Inorder traversal
{
  if(root->left!=NULL)
    in_order(root->left);
  printf("%d ",root->key);
  if(root->right!=NULL)
    in_order(root->right);
}
void post_order(Tree *root) //Postorder traversal
{
  if(root->left!=NULL)
    post_order(root->left);
  if(root->right!=NULL)
    post_order(root->right);
   printf("%d ",root->key);
}

int main() //Driver program
{
  int a;
  Tree *root=NULL;
  scanf("%d",&a);
  while(a!=-1)
  {
    root=insert(root,a);
    scanf("%d",&a);
  }
  printf("Preorder: ");
  pre_order(root);
  printf("\n");
  printf("Inorder: ");
  in_order(root);
  printf("\n");
  printf("Postorder: ");
  post_order(root);
  printf("\n");
  return 0; 
} 
