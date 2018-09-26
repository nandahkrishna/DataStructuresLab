#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct queue Queue;
struct queue //Linked list queue with additional 'p' for priority
{
  int c;
  int p;
  Queue* next;
};
Queue* newData()
{
  return (Queue*)malloc(sizeof(Queue));
}
void enqueue(Queue** front, Queue** rear, int a, int q) //Enqueue based on priority
{
  Queue* n = newData();
  n->c = a;
  n->p = q;
  n->next = NULL;
  if((*front)==NULL) {
    *front = n;
    *rear = n;
  }
  else {
    Queue* t = newData();
    Queue* temp = NULL;
    t->c = 0; t->p = 0; t->next = *front;
    for(temp = t; ((temp)->next!=NULL) && (n->p >= (temp)->next->p);
    (temp) = (temp)->next);
    n->next = (temp)->next;
    (temp)->next = n;
    *front = t->next;
    for(temp = t; (temp)->next!=NULL; (temp)=(temp)->next); 
    *rear = temp;
  }
}
void dequeue(Queue** front, Queue** rear, int* a, int* q) //Dequeue front
{
  if((*front)==NULL) printf("Empty\n\n");
  else {
    Queue* t = *front;
    *a = (*front)->c;
    *q = (*front)->p;
    *front = (*front)->next;
    free(t);
    if((*front)==NULL) *rear = NULL;
  }
}
void print(Queue* front) //Print the queue
{
  if(front==NULL) printf("Empty\n\n");
  else {
    for(Queue* temp = front; temp != NULL; temp = temp->next)
      printf("%d P:%d\n", temp->c, temp->p);
    printf("\n");
  }
}
int main() //Sample code
{
  Queue *front = NULL, *rear = NULL; int a, q, r;
  srand(time(0));
  for(int i = 0; i < 5; i++) {
    r = rand()%10 + 1;
    enqueue(&front,&rear,i,r);
  }
  print(front);
  dequeue(&front, &rear, &a, &q);
  print(front);
  for(;front!=NULL;) dequeue(&front, &rear, &a, &q);
  dequeue(&front, &rear, &a, &q);
  print(front);
  enqueue(&front, &rear, 1, 2);
  enqueue(&front, &rear, 1, 1);
  print(front);
  return 0;
}
