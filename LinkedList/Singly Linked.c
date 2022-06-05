#include <stdio.h>
#include <stdlib.h>

typedef struct MyList{
     int data;
     struct MyList *next;
}node;

int main(){
  node *a = (node*)malloc(sizeof(node));
  node *b = (node*)malloc(sizeof(node));
  node *c = (node*)malloc(sizeof(node));

  a->data = 7;
  b->data = 2;
  c->data = 6;

  a->next = b;
  b->next = c;
  c->next =NULL;

   printf("The Linked List: ");
    while(a!=NULL){
        printf(" %d -> ",a->data);
        a = a->next;
    }
        printf("NULL\n\n");
}

