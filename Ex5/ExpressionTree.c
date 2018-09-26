#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct tree //Tree structure
{
  char key;
  struct tree *left, *right;
};
typedef struct tree Tree;
struct node //Stack of trees
{
  Tree *data;
  struct node *back;
};
typedef struct node Node;
Tree *gettree()
{
  return (Tree *)malloc(sizeof(Tree));
}
Node *getnode()
{
  return (Node *)malloc(sizeof(Node));
}
Node *push(Node *top, Tree *root) //Add element to stack - push
{
  if(top==NULL)
  {
    top=getnode();
    top->data=root;
    top->back=NULL;
  }
  else
  {
    Node *temp=getnode();
    temp->data=root;
    temp->back=top;
    top=temp;
  }
  return top;
}
Node *pop(Node *top) //Pop from tree
{
  Node *p=top;
  if(top!=NULL)
    top=top->back;
  free(p);
  return top;
}
Node *in2tr(Node *top, char *infix) //Infix expression to tree
{
  Tree *b[100],*p,*z;
  int i=0,j=0;
  while(infix[i]!='\0')
  {
    p=gettree();
    char q=infix[i];
    p->key=q;
    p->left=p->right=NULL;
    if(isdigit(q))
    {
      b[j]=p;
      j++;
    }
    else if(q=='(')
    {
      top=push(top,p);
    }
    else if(q=='+' || q=='-')
    {
      if(top==NULL || top->data->key=='(')
	      top=push(top,p);
      else
      {
	      z=top->data;
	      top=pop(top);
	      j--;
	      z->right=b[j];
	      z->left=b[j-1];
	      b[j-1]=z;
	      top=push(top,p);
      }
    }
    else if(q=='*' || q=='/' || q=='%')
    {
      if(top==NULL || top->data->key=='(' || top->data->key=='+' || top->data->key=='-')
	      top=push(top,p);
      else
      {
	      z=top->data;
	      top=pop(top);
	      j--;
	      z->right=b[j];
	      z->left=b[j-1];
	      b[j-1]=z;
	      top=push(top,p);
      }
    }
    else if(q=='^')
      top=push(top,p);
    else if(q==')')
    {
      while(top!=NULL)
      {
	      if(top->data->key=='(')
	      {
	        top=pop(top);
	        break;
	      }
	      else
	      {
	        z=top->data;
	        top=pop(top);
	        j--;
	        z->right=b[j];
	        z->left=b[j-1];
	        b[j-1]=z;
	      }
      }
    }
    i++;
  }
  while(top!=NULL)
  {
    if(top->data->key!='(')
    {
      z=top->data;
      j--;
      z->right=b[j];
      z->left=b[j-1];
      b[j-1]=z;
    }
    top=pop(top);
  }
  top=push(top,b[0]);
  return top;
}
void postorder(Tree *root) //Gives postfix expression from tree
{
  if(root->left!=NULL)
    postorder(root->left);
  if(root->right!=NULL)
    postorder(root->right);
  printf("%c",root->key);
}
int main() //Driver program
{
  Node *top=NULL;
  char *infix=(char *)malloc(sizeof(100));
  scanf("%s",infix);
  top=in2tr(top,infix);
  postorder(top->data);
  printf("\n");
  return 0;
}
