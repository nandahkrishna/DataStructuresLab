#include<stdio.h>
#include<stdlib.h>
typedef struct queue Queue;
struct queue //Queue as linked list
{
  Queue* back;
  int c;
  Queue* next;
};
Queue* newData()
{
  return (Queue*)malloc(sizeof(Queue));
}
void enqueue(Queue** front, Queue** rear, int a) //Enqueue at rear
{
  Queue* n = newData();
  n->back = NULL;
  n->c = a;
  n->next = NULL;
  if((*front)==NULL) {
    *front = n;
    *rear = n;
  }
  else {
    n->back = *rear;
    (*rear)->next = n;
    (*rear) = n;
  }
}
void dequeue(Queue** front, Queue** rear, int* a) //Dequeue at front
{
  if((*front)==NULL) printf("Empty\n");
  else {
    Queue* t = *front;
    *a = (*front)->c;
    *front = (*front)->next;
    if((*front)!=NULL) (*front)->back = NULL;
    free(t);
    if((*front)==NULL) *rear = NULL;
  }
}
void print(Queue* front) //Print forward
{
  if(front==NULL) printf("Empty\n");
  else {
    for(Queue* temp = front; temp != NULL; temp = temp->next)
      printf("%d ", temp->c);
    printf("\n");
  }
}
void enqueuer(Queue** rear, Queue** front, int a) //Enqueue at front
{
  Queue* n = newData();
  n->next = NULL;
  n->c = a;
  n->back = NULL;
  if((*rear)==NULL) {
    *front = n;
    *rear = n;
  }
  else {
    n->next = *front;
    (*front)->back = n;
    (*front) = n;
  }
}
void dequeuer(Queue** rear, Queue** front, int* a) //Dequeue at rear
{
  if((*rear)==NULL) printf("Empty\n");
  else {
    Queue* t = *rear;
    *a = (*rear)->c;
    *rear = (*rear)->back;
    if((*rear)!=NULL) (*rear)->next = NULL;
    free(t);
    if((*rear)==NULL) *front = NULL;
  }
}
void printr(Queue* rear) //Print reverse
{
  if(rear==NULL) printf("Empty\n");
  else {
    for(Queue* temp = rear; temp != NULL; temp = temp->back)
      printf("%d ", temp->c);
    printf("\n");
  }
}
int main() //Sample operations
{
  Queue *front = NULL, *rear = NULL; int a;
  for(int i = 0; i < 5; i++) enqueue(&front,&rear,i);
  print(front);
  printr(rear);
  dequeue(&front, &rear, &a);
  print(front);
  dequeuer(&rear, &front, &a);
  printr(rear); 
  for(;front!=NULL;) dequeue(&front, &rear, &a);
  dequeuer(&rear, &front, &a);
  print(front);
  enqueuer(&rear, &front, 1); 
  enqueuer(&rear, &front, 2);
  enqueuer(&rear, &front, 3);
  enqueue(&front, &rear, 0);
  print(front);
  printr(rear);
  return 0;
}
