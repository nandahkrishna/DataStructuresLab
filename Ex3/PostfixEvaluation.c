#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef struct stack Stack;
struct stack //Stack linked list implementation
{
  int c;
  Stack* next;
};
Stack* newData()
{
  return (Stack*)malloc(sizeof(Stack));
}
Stack* push(Stack* top, int a) //Push to stack
{
  Stack* n = newData();
  n->c = a;
  n->next = top;
  top = n;
  return top;
}
Stack* pop(Stack* top, int* a) //Pop from stack
{
  Stack* t = top;
  *a = top->c;
  top = top->next;
  free(t);
  return top;
}
void print(Stack* top) //For checking stack status
{
  for(Stack* temp = top; temp != NULL; temp = temp->next)
    printf("%d ", temp->c);
  printf("\n");
}
Stack* op(char x[], Stack* top) //Logic for evaluation, x is operator or number
{
  int pop1, pop2, r;
  if(strcmp(x,"+")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pop1 + pop2;
      top = push(top, r);
  }
  else if(strcmp(x,"-")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pop2 - pop1;
      top = push(top, r);
  }
  else if(strcmp(x,"*")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pop1 * pop2;
      top = push(top, r);
  }
  else if(strcmp(x,"/")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pop2 / pop1;
      top = push(top, r);
  }
  else if(strcmp(x, "%")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pop2 % pop1;
      top = push(top, r);
  }
  else if(strcmp(x, "^")==0) {
      top = pop(top, &pop1);
      top = pop(top, &pop2);
      r = pow(pop2, pop1);
      top = push(top, r);
  }
  else top = push(top, atoi(x));
  return top;
}
int compute() //Invokes op()
{
  int r;
  char x[1000];
  Stack* top = NULL;
  gets(x);
  char* ptr = strtok(x, " ");
  while(ptr!=NULL) {
    top = op(ptr, top);
    ptr = strtok(NULL, " ");
  }
  top = pop(top, &r);
  return r;
}
int main() //Driver program
{
  int result;
  result = compute();
  printf("\n%d\n", result);
  return 0;
}
