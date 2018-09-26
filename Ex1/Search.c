#include<stdio.h>
#include<stdlib.h>
int a[10] = {6, 2, 4, 5, 8, 7, 1, 3, 9, 0}; //Test array
void sort() //Bubble sort for array
{
  for(int i = 0; i < 10; i++)
    for(int j = 0; j < 10; j++)
      if(a[j] > a[j+1]) {
	      int t = a[j];
	      a[j] = a[j+1];
	      a[j+1] = t;
      }
}
int linear(int s) //Linear Search in array
{
  for(int i = 0; i < 10; i++)
    if(a[i]==s) return i;
  return -1; //Not found
}
int binarys(int l, int h, int t) //Binary Search in array and number of steps
{
  static int i = 0; //Step counter
  int mid = (l + h)/2;
  if(l > h) { printf("\n%d steps ", i); return -1; } //Not found
  i++;
  if(a[mid]==t) { printf("\n%d steps ", i);  return 1; }
  else if(a[mid] < t) return binarys(mid + 1, h, t);
  else return binarys(l, mid, t);
}
struct node {
  int key;
  struct node* next;
};
typedef struct node Node; //Node for linked list
Node* prepend(int k, Node* p) //Prepend an element to list
{
  Node* n = (Node*)malloc(sizeof(Node));
  n->key = k;
  n->next = p;
  return n;
}
int linearl(Node* p,int s) //Linear Search in linked list
{
  while(p!=NULL) {
    if(p->key==s) return 1;
    p = p->next;
  }
  return -1; //Not found
}
int main()
{
  int t, u;
  Node* p = NULL;
  p = prepend(2,prepend(3,prepend(4,p))); //Test list
  scanf("%d", &t); //Element to search
  printf("%d %d\n", linear(t), linearl(p,t)); //Linear Search
  sort();
  printf("%d\n", binarys(0,10,t)); //Binary Search
  return 0;
}
