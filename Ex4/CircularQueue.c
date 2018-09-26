#include<stdio.h>
#include<stdlib.h>
typedef struct queue Queue;
struct queue //Linked list Queue
{
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
  n->c = a;
  if((*front)==NULL) {
    *front = n;
  }
  else {
    (*rear)->next = n;
  }
  (*rear) = n;
  (*rear)->next = *front;
}
void dequeue(Queue** front, Queue** rear, int* a) //Dequeue front
{
  if((*front)==NULL) printf("Empty\n");
  else if(*front == *rear) {
    *a = (*front)->c;
    free(*front);
    *front = NULL;
    *rear = NULL;
  }
  else {
    Queue* t = *front;
    *a = (*front)->c;
    *front = (*front)->next;
    (*rear)->next = *front; 
    free(t);
  }
}
void print(Queue* front) //Print
{
  if(front==NULL) printf("Empty\n");
  else {
    Queue* temp;
    for(temp = front; temp->next != front; temp = temp->next)
      printf("%d ", temp->c);
    printf("%d", temp->c);
    printf("\n");
  }
}
int main() //Sample operations
{
  Queue *front = NULL, *rear = NULL; int a;
  for(int i = 0; i < 5; i++) enqueue(&front,&rear,i);
  print(front);
  dequeue(&front, &rear, &a);
  print(front);
  for(;front!=NULL;) dequeue(&front, &rear, &a);
  dequeue(&front, &rear, &a);
  print(front);
  enqueue(&front, &rear, 1);
  print(front);
  return 0;
}
