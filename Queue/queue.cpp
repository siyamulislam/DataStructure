#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int font=0,rear=0;
int Q[CAPACITY];

void enq(void);
void deq(void);
void dis(void);

int main()
{
    int key;
    printf("\tSimple queue\n\n");
    printf("Press 1. Enqueue\n");
    printf("Press 2. Dequeue\n");
    printf("Press 3. Display\n");
    printf("Press 4. Exit\n");

    while(1)
    {
        printf("Press your Choice: ");
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
            dis();
            break;
        case 4:
            exit(1);
        default :
            printf("Wrong choice \n");
            break;
        }
    }
}

void enq()
{
    if(CAPACITY==rear)
    {
        printf("Queue is Full!!\n");
    }
    else
    {
        int data;
        printf("Enter Data: \n");
        scanf("%d",&data);
        Q[rear]=data;
        rear++;
    }
}

void deq()
{
    if(font==rear)
    {
        printf("Queue is Empty!\n");
    }
    else
    {
        int i;
        printf("%d is Deleted!!\n",Q[font]);
        for(i=0; i<rear-1; i++)
        {
            Q[i]=Q[i+1];
        }
        rear--;
    }
}

void dis()
{
    int i;
    if(font==rear)
    {
        printf("Queue is Empty!\n");
    }
    printf("Your Queue Elements: \n");
    for(i=font; i<rear; i++)
    {
        printf("%d ",Q[i]);
    }
    printf("\n");
}
