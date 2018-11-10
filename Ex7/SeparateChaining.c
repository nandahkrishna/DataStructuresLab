#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* create_node(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void insert(struct node* hashTable[], int index, int key)
{
    struct node* pos = hashTable[index];
    struct node* temp = create_node(key);
    if(pos == NULL)
        hashTable[index] = temp;
    else
    {
        while(pos->next != NULL)
            pos = pos->next;
        pos->next = temp;
    }
}
int hashFunc(int k)
{
    return k%10;
}
void retrieve(struct node* hashTable[], int key)
{
    char ch = 'y', d;
    int i = 0;
    d = hashFunc(key);
    struct node* pos = hashTable[d];
    printf("Search Results: \n");
    while(ch == 'y' && pos != NULL)
    {
        printf("%d \n", pos->data);
        if(pos->data == key) ch = 'n';
        else pos = pos->next;
    }
    if(ch == 'y')
        printf("Not found!");
}
int main()
{
    struct node *hashTable[10] = {NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL};
    int i, key;
    for(i = 0; i < 30; i++) {
        key = rand()%200;
        insert(hashTable, hashFunc(key), key);
    }
    printf("Enter Key: ");
    scanf("%d", &key);
    retrieve(hashTable, key);
    printf("\n");
    return 0;
}
