#include<stdio.h>
int Q[101], front = -1, rear = -1;
void enqueue(int a) //Enqueue a value (at rear)
{
  if(front==-1&&rear==-1) {
    front = 0; rear = 0;
    Q[rear] = a;
  }
  else if(rear==100) {
    printf("Full\n");
  }
  else {
    rear++; Q[rear] = a;
  }
}
void dequeue(int* a) //Dequeue first element
{
  if(front==-1) printf("Empty\n");
  else {
    *a = Q[front]; front++;
    if(front==rear) {
      rear = -1; front = -1;
    }
  }
}
void print() //Print the queue
{
  if(front==-1) printf("Empty\n");
  else {
    for(int i = front; i <= rear; i++)
      printf("%d ", Q[i]);
    printf("\n");
  }
}
int main() //Sample code
{
  int a;
  for(int i = 0; i < 5; i++) enqueue(i);
  print();
  dequeue(&a);
  print();
  for(;front!=-1;) dequeue(&a);
  dequeue(&a);
  print();
  enqueue(1);
  print();
  return 0;
}
