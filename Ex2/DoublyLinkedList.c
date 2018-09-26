#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*back;
}; //Node for list
void display(struct node* head) //Forward display
{
    struct node *temp;
    printf("\n");
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d ",temp->data);
    }
}
void display_rev(struct node* tail) //Reverse display
{
    struct node *temp;
    printf("\n");
    for(temp=tail;temp!=NULL;temp=temp->back)
    {
        printf("%d ",temp->data);
    }
}
struct node* insert(struct node* head, int ref, int val) //Insert after
{
    struct node *temp,*curr;
    for(temp=head;temp->data!=ref;temp=temp->next);
    {
        curr=(struct node *)malloc(sizeof(struct node));
        curr->data=val;
        curr->next=temp->next;
        curr->next->back=curr;
        temp->next=curr;
        curr->back=temp;
    }
    return head;
}
struct node* ins_tail(struct node *tail, int val) //Insert at tail
{
     struct node *curr;
     curr=(struct node *)malloc(sizeof(struct node));
     curr->data=val;
     curr->next=NULL;
     tail->next=curr;
     curr->back=tail;
     tail=curr;
     return tail;
}
struct node * ins_head(struct node * head, int val) //Insert at head
{
    struct node * curr;
    curr=(struct node *)malloc(sizeof(struct node));
    curr->data=val;
    curr->back=NULL;
    curr->next=head;
    head->back=curr;
    head=curr;
    return(head);
}
struct node* ins_node(struct node *head, struct node *tail, int ref, int val) //General insert
{
    if(ref==-99) //-99 is assumed not permitted to store
    {
        return ins_head(head,val);
    }
    else if(ref==tail->data)
    {
        return ins_tail(tail,val);
    }
    else
    {
        return insert(head,ref,val);
    }
}
struct node* delete(struct node *head, int d) //Delete value
{
    struct node *temp;
    for(temp=head;temp!=NULL&&temp->data!=d;temp=temp->next);
    temp->back->next=temp->next;
    temp->next->back=temp->back;
    return head; 
}
struct node* delhead(struct node* head) //Delete head
{
    head=head->next;
    free(head->back);
    head->back = NULL;
    return head;
}
struct node* deltail(struct node * tail) //Delete tail
{
    struct node * p = tail;
    tail = tail->back;
    tail->next = NULL;
    free(p);
    return tail;
}
struct node* del(struct node* head,struct node* tail, int val) //General delete
{
    if(head->data==val)
        return delhead(head);
    else if(tail->data==val)
        return deltail(tail);
    else 
        return delete(head,val);
}
void disp(struct node *ptr) //Display general
{
    if(ptr->next==NULL)
    {
        display_rev(ptr);
    }
    else
    {
        display(ptr);
    }
}
int main(void) //Contains sample operations
{  
    struct node *temp, *prev, *head, *tail;
    head = NULL;
    int i=0;
    for(i=0;i<5;i++)
    {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=i;
    temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            head->back=NULL;
            prev=head;
        }
        else
        {
            prev->next=temp;
            temp->back=prev;
            prev=temp;
        }
        
    }
    tail=temp;
    disp(head);
    disp(tail);
    head=ins_node(head,tail,2,7);
    display(head);
    display_rev(tail);
    tail=ins_node(head,tail,tail->data,8);
    display(head);
    display_rev(tail);
    head=ins_node(head,tail,-99,0);
    display(head);
    display_rev(tail);
    head=del(head,tail,2);
    display(head);
    display_rev(tail);
    head=del(head,tail,head->data);
    display(head);
    display_rev(tail);
    tail=del(head,tail,tail->data);
    display(head);
    display_rev(tail);
    return 0;
}
