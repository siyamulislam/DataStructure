#include <stdio.h>
#include <stdlib.h>

struct node
{
    int x;
    float y;
    struct node *next;
};
struct node* node=NULL;

int main(){
  struct node *head = (struct node*)malloc(sizeof(node));
  struct node *headNext = (struct node*)malloc(sizeof(node));

  head->x = 4;
  head->y = 1.2;

  headNext->x = 7;
  headNext->y = 1.8;

  head->next = headNext;
  headNext->next = NULL;

   printf("Output: ");
    while(head!=NULL){
        printf(" %d  ",head->x);
        printf("%.1f -> ",head->y);
        printf("\t");
        head = head->next;
    }
        printf("NULL\n\n");
}


