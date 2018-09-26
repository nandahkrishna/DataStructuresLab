#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
  int key;
  Node* next;
}; //Linked list node
Node* getNode()
{
  return (Node*)malloc(sizeof(Node));
}
Node* insert(Node* head, int val, int aft, int c)
{
  Node* temp = NULL;
  if(c==1) { //Insert after value
    for(temp = head;  temp != NULL && temp->next != NULL && temp->key != aft; temp = temp->next);
    Node* n = getNode();
    n->key = val;
    if(head == NULL) {
      return NULL;
    }
    else {
      n->next = temp->next;
      temp->next = n;
    }
  }
  else if(c==2) { //Insert at head
    if(head==NULL) {
      head = getNode();
      head->key = val;
      head->next = NULL;
    }
    else {
      Node* n = getNode();
      n->key = val;
      n->next = head;
      head = n;
    }
  }
  else if(c==3) { //Insert at tail - append
    if(head==NULL) {
      head = getNode();
      head->key = val;
      head->next = NULL;
    }
    else {
      for(temp = head;  temp->next != NULL; temp = temp->next);
      Node* n = getNode();
      n->key = val;
      n->next = NULL;
      temp->next = n;
    }
  }    
  return head;
}
Node* delNode(Node* head, int val, int c)
{
  if(head == NULL) return head;
  Node* temp = NULL;
  if(c==1) { //Delete value
    temp = head;
    if(head->key==val) {
      head = head->next;
      free(temp);
    }
    else {
      for(temp = head; temp->next->next!=NULL && temp->next->key != val; temp = temp->next);
      Node* p = temp->next;
      temp->next = temp->next->next;
      free(p);
    }
  }
  else if(c==2) { //Delete head
    Node* p = head;
    head = head->next;
    free(p);
  }
  else if(c==3) { //Delete tail
    if(head->next == NULL) {
      temp = head;
      head = NULL;
      free(temp);
    }
    else {
      for(temp = head; temp->next->next != NULL; temp = temp->next);
      Node* p = temp->next;
      temp->next = temp->next->next;
      free(p);
    }
  }
  return head;
}
void display(Node* head)
{
  for(Node* temp = head; temp != NULL; temp = temp->next)
    printf("%d ", temp->key);
  printf("\n");
}
int main()
{
  Node *head;
  char c = '1';
  int val = 0, aft = 0;
  head = NULL;
  printf("1.Insert:(val,aft) 2.Insert head 3. Insert tail\n4.Delete:(val) 5.Delete head 6.Delete tail\n7.Display\nQ.Quit\n");
  do { 
    scanf("%c", &c);
    switch(c) {
    case '1':
      scanf("%d %d", &val, &aft);
      head = insert(head, val, aft, 1);
      break;
    case '2':
      scanf("%d", &val);
      head = insert(head, val, aft, 2);
      break;
    case '3':
      scanf("%d", &val);
      head = insert(head, val, aft, 3);
      break;
    case '4':
      scanf("%d", &val);
      head = delNode(head, val, 1);
      break;
    case '5':
      head = delNode(head, val, 2);
      break;
    case '6':
      head = delNode(head, val, 3);
      break;
    case '7':
      display(head);
      break;
    }
  }while(c!='Q'&&c!='q');
  return 0;
}
