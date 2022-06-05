#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void insert(Node *current, int data);
void delete(Node *current, int data);
void print(Node *current);
int find(Node *current, int data);

void insert(Node *current, int data) {

    while(current->next != NULL) {
        current = current->next;
    }
    current->next = (Node *)malloc(sizeof(Node));
    (current->next)->prev = current;
    current = current->next;
    current->data = data;
    current->next = NULL;
}

void delete(Node *current, int data){
    while (current->next != NULL && (current->next)->data != data) {
        current = current->next;
    }
    if(current->next == NULL) {
        printf("\nElement %d is not present in the list\n", data);
        return;
    }
    Node *tmp = current->next;
    if(tmp->next == NULL) {
        current->next = NULL;
    } else {
        current->next = tmp->next;
        (current->next)->prev = tmp->prev;
    }
    tmp->prev = current;
    free(tmp);

    return;
}
void print(Node *current) {
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int find(Node *current, int data) {
    current = current->next;

    while(current != NULL) {
        if(current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {

    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->prev = NULL;

    int data = 0;
    int usr_input = 0;

    while(1){
        printf("0. Exit\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Find\n");


        scanf("%d", &usr_input);

        if( usr_input == 0) {
            exit(0);

        } else if(usr_input == 1) {
            printf("\nEnter an element you want to insert: ");
            scanf("%d", &data);
            insert(head, data);

        } else if(usr_input == 2) {
            printf("\nEnter an element you want to delete: ");
            scanf("%d", &data);
            delete(head, data);

        } else if(usr_input == 3) {
            printf("The list is ");
            print(head->next);
            printf("\n\n");

        } else if(usr_input == 4) {
            printf("\nEnter an element you want to find: ");
            scanf("%d", &data);
            int is_found = find(head, data);
            if (is_found) {
                printf("\nElement is found\n\n");
            } else {
                printf("\nElement is NOT found\n\n");
            }
        }
    }
    return 0;
}
