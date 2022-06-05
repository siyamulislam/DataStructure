#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 5

int stack[CAPACITY], top=-1 ;

void Push(int);
int Pop(void);
void Peek(void);
void Display(void);
int isempty(void);
int isfull(void);

void main()
{
    int ch,item;

    printf("\n~~~~~~~~~~~~Stack~~~~~~~~~~~~~\n\n");

    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Quit\n");
    while(1)
    {
        printf("\nPress ur choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("Enter Element : ");
            scanf("%d",&item);
            Push(item);
            break;

        case 2:
            item = Pop();
            if(item == 0)
            {
                printf("Stack Underflow!\n");
            }
            else
            {
                printf("Popped Successfully!\n");
            }
            break;
        case 3:
            Peek();
            break;
        case 4:
            Display();
            break;
        case 5:
            exit(1);
        default:
            printf("Invalid Choice\n");
        }
    }
}

void Push(int ele)
{
    if(isfull())
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        stack[top]=ele;
        printf("Pushed Successfully!\n");
    }
}

int Pop()
{
    if(isempty())
    {
        return 0;
    }
    else
    {
        //top--;
        return stack[top--];
        printf("Popped Successfully!\n");
    }
}

void Peek()
{
    if(isempty())
    {
        printf("Stack is Empty!\n");
    }
    else
    {
        printf("Peek Element : %d\n",stack[top]);
    }

}

void Display()
{
    if(isempty())
    {
        printf("Stack is Empty!\n");
    }
    else
    {
     int i;
    printf("Stack Elements:\n");
    for(i=0; i<=top; i++)
    {
        printf("%d\n",stack[i]);
    }
    }
}

int isempty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isfull()
{
    if(top==CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
