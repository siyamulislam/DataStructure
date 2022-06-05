#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head;
void insert_beginning(int n)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    if(head != NULL)
    {
        temp->next = head;
    }
    head = temp;
}
void insert_at_any_position(int data,int n)
{
    int i;
    struct node* temp2 = head;
    struct node*temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next = NULL;
    for(i=0; i<n-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}
void insert_end(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = data;
    temp -> next = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node* temp1;
        temp1= head;
        while(temp1 -> next != NULL)
        {
            temp1 = temp1 -> next;
        }
        temp1 -> next= temp;
    }
}
void display(int data)
{
    printf("your elements are : ");
    struct node* temp;
    //temp = (struct node*)malloc(sizeof(struct node));
    temp = head;

    while(temp != NULL)
    {
        printf("%d ,",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void delete_beginning(int data)
{
    struct node* temp = head;
    //temp = head;
    if(head == NULL)
    {
        return;
    }
    else
    {
        head = temp->next;

        // return 0;
    }
    free(temp);

}
void delete_at_any_position(int data, int n)
{
    int i;
    struct node* temp = head;
    if(n==1)
    {
       head=temp->next;

            free(temp);
    }
    else{
    for(i=0; i<n-2; i++)
    {
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
    }
}
void delete_end(int data)
{
    struct node* temp;
    struct node* temp1;
    temp = head;

     if(temp==NULL)
        return;
    if(temp->next==NULL)
    {
       head=temp->next;

            free(temp);
    }

   else if(temp->next != NULL)
    {

        while(temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        //head = temp1;
        temp1->next = NULL;
        free(temp);
    }

}
void search(int data,int n)




{
    int count = 0;
    struct node* temp = head;
    while(temp != NULL)
    {

        //head =temp;
        if(temp->data == data)
        {
            count++;
        }
        temp = temp->next;
    }
    printf("Total result found: %d\n",count);
}
void countNode()
{
    struct node*temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Total nodes found %d\n",count);
}
int main()
{
    int key,a,num;
    printf(" 1.Insert at the beginning\n 2.insert at any position\n 3.Insert at the end\n 4.delete at the beginning\n 5.delete at any position\n 6.Delete at the end\n 7.Display\n 8.Search\n 9.Count Node\n 10.Exit\n");
    while(1)
    {
        printf("Enter your choices: ");
        scanf("%d",&key);
        switch(key)
        {
        case 1:
            printf("Enter data at beginning:");
            scanf("%d",&a);
            insert_beginning(a);
            break;
        case 2:
            printf("Enter position :");
            scanf("%d",&num);
            printf("Enter data :");
            scanf("%d",&a);
            insert_at_any_position(a,num);
            break;
        case 3:
            printf("Enter a data :");
            scanf("%d",&a);
            insert_end(a);
            break;
        case 4:
            //printf("delete data at beginning :");
            //scanf("%d",num);
            delete_beginning(a);
            break;
        case 5:
            printf("Enter position :");
            scanf("%d",&num);
            printf("Enter number to delete :");
            scanf("%d",&a);
            delete_at_any_position(a,num);
            break;
        case 6:
            delete_end(a);
            break;
        case 7:

            display(a);
            break;
        case 8:
            printf("Enter number to search :");
            scanf("%d",&num);
            search(num,a);
            break;
        case 9:
            countNode();
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
            break;
        }
    }
}
