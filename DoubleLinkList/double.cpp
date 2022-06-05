#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL;

void insert()
{
    int value;
    printf("Enter Data: ");
    scanf("%d",&value);
    struct node *temp;
    struct node *p;
    p=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void print()
{
    struct node* p = head;
    if(p==NULL)
    {
        printf("List is empty!");
    }
    else
    {

        printf("First to last: ");
        while(p != NULL)
        {
            printf("%d ",p->data);
            p = p->next;
        }
        printf("\n");
    }
}
void print_rev()
{
    struct node* p=head;
    if(p==NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }

        printf("Reverse: ");
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->prev;
        }
        printf("\n");
    }
}
int main(void)
{
    printf("\n\t\t\t\tDOUBLE LINKED LIST\n");
    printf("1. Insert\n");
    printf("2. Print\n");
    printf("3. Reverse\n");
    printf("4. Exit.\n");

    while(1)
    {
        int key;
        printf("press your choice\n");
        scanf("%d",&key);
        switch(key)
        {
        case 1:
            insert();
            break;
        case 2:
            print();
            break;
        case 3:
            print_rev();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("Wrong Choice!!\n");
        }
    }
}



