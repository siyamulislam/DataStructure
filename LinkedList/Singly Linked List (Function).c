#include<stdio.h>
#include<stdlib.h>

typedef struct MyList{
  int data;
  struct MyList* next;
}node;

node* create(){
    return (node*)malloc(sizeof(node));
}

void insert_end(node* ptr, int data){
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->next = create();
    ptr->next->data = data;
    ptr->next->next = NULL;
}

void display(node* ptr){
    printf("The Linked List: ");
    while(ptr->next!=NULL){
        printf(" %d -> ",ptr->next->data);
        ptr = ptr->next;
    }
        printf("NULL\n\n");
}

int main(){
    node* head = create();
    head->next = NULL;

    insert_end(head,8);  //Inserting 8 in Linked List

    insert_end(head,5);   //Inserting 5 in Linked List

    insert_end(head,9);   //Inserting 9 in Linked List

    insert_end(head,7);   //Inserting 7 in Linked List

    insert_end(head,2);   //Inserting 2 in Linked List


    display(head);
}

