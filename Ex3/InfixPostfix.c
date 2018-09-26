#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int i = 0;
typedef struct stack Stack;
struct stack //Stack linked list implementation
{
  char c;
  Stack* next;
};
Stack* newData()
{
  return (Stack*)malloc(sizeof(Stack));
}
Stack* push(Stack* top, char a) //Push to stack
{
  Stack* n = newData();
  n->c = a;
  n->next = top;
  top = n;
  return top;
}
Stack* pop(Stack* top, char* a) //Pop from stack
{
  Stack* t = top;
  *a = top->c;
  top = top->next;
  free(t);
  return top;
}
void print(Stack* top) //Used to check stack status
{
  for(Stack* temp = top; temp != NULL; temp = temp->next)
  printf("%d ", temp->c);
  printf("\n");
}
int prec(char c) //Precedence for operators as per BODMAS
{
  switch(c) {
    case '+': return 1; break;
    case '-': return 1; break;
    case '/': return 2; break;
    case '*': return 2; break;
    case '%': return 2; break;
    case '^': return 3; break;
    case '(': return 0; break; //'(' has least precedence
    case ')': return 5; break; //')' is allotted 5
    default: return 4; break; //For numbers
  }
}
Stack* op(char x[], char pn[], Stack* top) //Conversion logic
{
  char popc;
  if(prec(x[0])<4&&!isdigit(x[1])) { //If operator
    if(top==NULL) {
      top = push(top, x[0]);
    }
    else {
      while(x[0]!='('&&prec(x[0])<prec(top->c)) {
        top = pop(top, &popc);
        pn[i++] = popc;
        pn[i++] = ' ';
      }
      top = push(top, x[0]);
    }
  }
  else if(x[0]==')') { //')' is encountered
    while(top->c!='(') {
      top = pop(top, &popc);
      pn[i++] = popc;
      pn[i++] = ' ';
    }
    top = pop(top, &popc);
  }
  else if((isdigit(x[0]))||(prec(x[0])==1&&isdigit(x[1]))) { //Numbers
    for(int j = 0; x[j] != '\0'; j++) {
      pn[i++] = x[j];
    }
    pn[i++] = ' ';
  }
  return top;
}
void convert(char pn[]) //Function that invokes op()
{
  char in[1000], popc;
  Stack* top = NULL;
  gets(in);
  char* ptr = strtok(in, " ");
  while(ptr!=NULL) {
    top = op(ptr, pn, top);
    ptr = strtok(NULL, " ");
  }
  while(top!=NULL) {
    top = pop(top, &popc);
    pn[i++] = popc;
    pn[i++] = ' ';
  }
}
int main()
{
  char pn[1000];
  convert(pn);
  pn[i] = '\0';
  printf("\n%s\n", pn);
  return 0;
}
