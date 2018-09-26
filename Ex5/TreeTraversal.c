#include<stdio.h>
#include<stdlib.h>
struct node //Node of tree
{
  int data;
  struct node* left,  *right;
};
struct node* newNode(int x)
{
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data=x;
	Node->left=NULL;
	Node->right=NULL;
	return Node;
}
void inOrder(struct node* tree) //Inorder traversal - LDR
{
	if(tree==NULL){return;}
	inOrder(tree->left);
	printf("%d\t",tree->data);
	inOrder(tree->right);
}
void postOrder(struct node* tree) //Postorder traversal - LRD
{
	if(tree==NULL){return;}
	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d\t",tree->data);
}
void preOrder(struct node* tree) //Preorder traversal - DLR
{
	if(tree==NULL){return;}
	printf("%d\t",tree->data);
	preOrder(tree->left);
	preOrder(tree->right);
}
int main() //Sample operations
{
	struct node* root=newNode(1);
	root->left=newNode(2);
	root->right=newNode(3);
	root->left->right=newNode(4);
	root->left->left=newNode(5);
	printf("inorder:");
	inOrder(root);
	printf("\n");
	printf("preorder:");
	preOrder(root);
	printf("\n");
	printf("postorder:");
	postOrder(root);
	printf("\n");
	return 0;
}
