#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;

void push(void);
void pop(void);
void display(void);
void fq(void);

void main()
{
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display.\n");
    printf("4. Frequency.\n");
    printf("5. Exit.\n");

    while(1)
    {
        int key;
        printf("press your choice\n");
        scanf("%d",&key);
        switch(key)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            fq();
            break;
        case 5:
            exit(1);
        }
    }
}

void push()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter Stack data: ");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        temp->link=root;
        root=temp;
    }
}

void pop()
{
    struct node* temp;
    {
        temp=root;
        if(temp==NULL)
        {
            printf("Stack is Empty!!\n");
        }
        else
        {
            root=temp->link;
            temp->link=NULL;
            free(temp);
        }
    }
}

void display()
{
    struct node* temp;
    temp =root;

    if(temp==NULL)
    {
        printf("Stack is Empty!!\n");
    }
    else
    {
        printf("Your Stack Elements: \n");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void fq()
{
    struct node* temp;
    temp =root;
    int search,count=0;
    printf("Enter data\n");
    scanf("%d",&search);

    printf("Your searched result\n");
    while(temp!=NULL)
    {
        if(search==temp->data)
        {
            count++;
        }
        temp=temp->link;
    }
    printf("Frequency = %d\n\n",count);
}
