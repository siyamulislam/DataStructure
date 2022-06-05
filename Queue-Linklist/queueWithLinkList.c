#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* front=NULL;
struct node* rear=NULL;

void enq(void);
void deq(void);
void display(void);

void main()
{
    printf("~~~~ Queue Implementation using Linked List~~~~\n\n");
    printf("1. EnQueue\n");
    printf("2. DeQueue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while(1)
    {
        int key;
        printf("\nPress your choice\n");
        scanf("%d",&key);
        switch(key)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong Choice!\n\n");
        }
    }
}

void enq()
{
    int value;
    struct node* temp;
    temp =(struct node*)malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d",&value);
    temp->data=value;
    temp->link=NULL;

    if (front==NULL && rear == NULL)
    {
        front=rear=temp;
        return;
    }
    else
    {
        rear->link=temp;
        rear=temp;
    }
}
void deq()
{
    struct node *temp;

    if(front==NULL)
    {
        printf("Queue is Underflow!!\n");
        return;
    }

    if(front==rear)
    {
        front=rear=NULL;
        return;
    }

    else
        temp=front;
    {
        front = front->link;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue is empty!!\n");
    }
    else
    {
        temp=front;
        printf("Queue Elements are: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
