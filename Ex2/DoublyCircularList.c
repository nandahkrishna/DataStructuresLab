#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next, *back;
}; //Node for list
typedef struct node Node;
void display(Node* head, int c) //Forward print
{
    Node* temp;
    int i=0;
     for(temp=head->next;i<c;temp=temp->next)
        {
            if(temp==head)
                i++;
            printf("%d ",temp->data);
        }
}
void displayr(Node* head, int c) //Reverse print
{
    Node* temp;
    int i=0;
     for(temp=head->back;i<c;temp=temp->back)
        {
            if(temp==head)
                i++;
            printf("%d ",temp->data);
        }
}
void ins_after(Node* head,int after,int new_value) //Insertion after value
{
    Node *temp=head;
    for(;temp->data!=after;temp=temp->next);
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=new_value;
    newnode->next=temp->next;
    newnode->back=temp;
    temp->next=newnode;
    newnode->next->back=newnode;
    
}
void delete(struct node* head,int ref) //Deletion of a value
{

   struct node* temp;
    for(temp=head->next;temp!=head;temp=temp->next)
    {
      if(temp->next->data==ref) {
            temp->next=temp->next->next;
	          temp->next->back = temp;
      }
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
        if(head==NULL)
        {
	        temp->next=temp;
	        temp->back=temp;
          head=temp;
	        prev=head;
        }
        else
        {
	        prev->next=temp;
	        temp->back=prev;
	        temp->next=head;
	        head->back=temp;
	        prev=temp;
        }
    }
    display(head,1);
    ins_after(head,0,8);
    printf("\n");
    display(head,1);
    displayr(head,1);
    delete(head,3);
    printf("\n");
    display(head,1);
    displayr(head,1);
    return 0;
}
