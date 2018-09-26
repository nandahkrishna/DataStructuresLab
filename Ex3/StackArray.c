#include<stdio.h>
#define size 10
void push(int stack[], int item, int *top) //Push to stack
{
  if (*top == size - 1)
  {
    printf("Stack is full\n");
  }
  else
  {
    (*top)++;
    stack[ *top] = item;
  }
}
int pop(int stack[], int *top) //Pop from stack
{
  int value;
  if (*top == - 1)
  {
    return - 1; //Empty stack
  }
  else
  {
    value = stack[ *top];
    (*top)--;
    return value;
  }
}
int main() //Sample operations
{
  int stack[size], Top = - 1, data;
  for(int i = 0; i < 12; i++) push(stack,i,&Top); //Sample push
  printf("Pushed, now Pop:\n");
  for(int i = 0; i < 12; i++) {
    data = pop(stack, &Top); //Sample pops
    data==-1 ? printf("Empty\n"):printf("%d\n",data); //Empty check
  }
  return 0;
}
