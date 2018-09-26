#include<stdio.h>
#include<stdlib.h>
typedef struct node Node;
struct node
{
  int coeff, deg;
  Node *next;
}; //Each term of polynomial
Node* push(Node *top,int coeff,int deg) //Add term to polynomial
{
  if(coeff!=0) { 
      Node *n=(Node*)malloc(sizeof(Node));
      n->coeff=coeff;
      n->deg=deg;
      if(top==NULL) {
	      top=n;
	      n->next=NULL;
      }
      else {
	      n->next=top;
	      top=n;
      }
  }
  return top;
}

void display(Node *top,int max_deg) //Print
{
  Node *temp;
  int i = max_deg;
  for(temp=top;temp!=NULL;temp=temp->next,i--) {
      int t=temp->coeff>0?temp->coeff:-(temp->coeff);
      printf(" %dx^%d %c",t,temp->deg,temp->next==NULL?'\n':((temp->next->coeff>0)?'+':'-'));
  }
}
Node* read_poly(Node *poly,int max_degree) //Input for polynomial
{
  int i = 0, coeff;
  while(i<=max_degree) {
      printf("Coefficient for x^%d: ",i);
      scanf("%d",&coeff);
      if(coeff!=0) {
	      poly=push(poly,coeff,i);
      }
      i++;
  }
  return poly;
}

void add(Node *poly1,Node *poly2,Node **result,int max_degree,int curr_degree) //Add 2 polynomials
{
    int coeff=0;
    if(poly1==NULL||poly2==NULL) //One or both are empty
    {
      if(poly1!=NULL) //Second empty
      {
	      while(poly1!=NULL)
	      {
	          (*result)=push(*result,poly1->coeff,poly1->deg);
	          poly1=poly1->next;
	      }  
      }
      if(poly2!=NULL) //First empty
      {
	      while(poly2!=NULL)
	      {
	         (*result)=push(*result,poly2->coeff,poly2->deg);
	         poly2=poly2->next; 
	      }
      }
    }
    else if(poly1->deg==poly2->deg) //Equal degree terms
    {
      coeff=poly1->coeff+poly2->coeff;
      curr_degree=poly1->deg;
      add(poly1->next,poly2->next,result,max_degree,curr_degree);
    }
    else if(poly1->deg>poly2->deg) //Degree of term from 1 > from 2
    {
      coeff=poly1->coeff;
      curr_degree=poly1->deg;
      add(poly1->next,poly2,result,max_degree,curr_degree);
    }
    else if(poly1->deg<poly2->deg) //Degree of term from 2 > from 1
    {
      coeff=poly2->coeff;
      curr_degree=poly2->deg;
      add(poly1,poly2->next,result,max_degree,curr_degree);
    }
    if(poly2!=NULL&&poly1!=NULL) //Push result of step if non-empty
    {
      *result=push(*result,coeff,curr_degree);
    }
      
}

int main() //Driver code
{
  Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
  int ch, coeff, deg;
  int maxd;
  printf("Enter maximum degree: ");
  scanf("%d", &maxd);
  poly1 = read_poly(poly1,maxd);
  display(poly1,maxd);
  poly2 = read_poly(poly2,maxd);
  display(poly2,maxd);
  add(poly1,poly2,&result,maxd,maxd);
  printf("\nResult:");
  display(result,maxd);
}
