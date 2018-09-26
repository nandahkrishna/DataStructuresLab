#include<stdio.h>
#include<stdlib.h>
struct node //Node of tree
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root) //Inorder traversal
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key) //Insert in BST
{
    if (node == NULL) return newNode(key); //Empty tree initially
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node * maxValueNode(struct node* node) //Maximum value of subtree, used to find Inorder predecessor
{
    struct node* current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}
struct node* search(struct node* root, int key) //Search in BST
{
    if (root == NULL || root->key == key)
       return root;
    if (root->key < key)
       return search(root->right, key);
    return search(root->left, key);
}
struct node* deleteNode(struct node* root, int key) //Deletion in BST
{
    if (root == NULL) return root; //Empty
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else //Matched key
    {
        if (root->left == NULL) //One right child or no children
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) //One left child
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //Two children
        struct node* temp = maxValueNode(root->left); //Inorder predecessor
        root->key = temp->key; //Assign to root
        root->left = deleteNode(root->left, temp->key); //Delete inorder predecessor
    }
    return root;
}
int main() // Sample BST operations
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Search for 10 \n");
    struct node *t = search(root, 10);
    (t==NULL)?printf("Not found\n"):printf("Found\n");

    printf("Inorder traversal of the given tree \n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
    printf("\n");
 
    return 0;
}
