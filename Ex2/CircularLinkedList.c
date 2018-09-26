#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}; //Node for list
typedef struct node Node;
void display(Node *head,int c) //Display list
{
    Node *temp;
    int i=0;
     for(temp=head->next;i<c;temp=temp->next)
        {
            if(temp==head)
                i++;
            printf("%d ",temp->data);
        }
}
void ins_after(Node* head,int after,int new_value) //Insertion after a value
{
    Node *temp=head;
    for(;temp->data!=after;temp=temp->next);
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=new_value;
    newnode->next=temp->next;
    temp->next=newnode;
    
}
void delete(struct node* head,int ref) //Delete a value
{

   struct node* temp;
    for(temp=head->next;temp!=head;temp=temp->next)
    {
        if(temp->next->data==ref)
            temp->next=temp->next->next;
        
    }
}
int main(void) //Contains sample operations
{
    struct node *head,*temp,*prev;
    head=NULL;
    int i=0;
    int c=0;
    for(i=0;i<5;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=i;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            prev=head;
            
        }
        else
        {
            prev->next=temp;
            prev=temp;
        }
    }
    temp->next=head;
 	  display(head,1);
    ins_after(head,0,8);
    printf("\n");
    display(head,1);
    delete(head,3);
    printf("\n");
    display(head,1);
    return 0;
}
