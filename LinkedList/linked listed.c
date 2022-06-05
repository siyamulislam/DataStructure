#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* root=NULL;

void insert()
{
    struct node* temp;
    temp= (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&temp->data);
    temp->link= NULL;
    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        struct node* p;
        p=root;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
}

int length()
{
    int count=0;
    struct node* temp;
    temp=root;
    while(temp!=NULL)
    {
        count++;
        temp= temp->link;
    }
    return count;
}

void insert_begenning()
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
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

void insert_after()
{
    struct node* temp,*p;
    int loc,len,i=1;
    printf("Enter location: ");
    scanf("%d",&loc);
    len= length();
    if(loc>len)
    {
        printf("Invalid Location.\n");
        printf("Current Location is Having %d.\n",len);
    }
    else
    {
        p=root;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d",&temp->data);
        temp->link=NULL;
        temp->link=p->link;
        p->link=temp;
    }
}

void display()
{
    struct node* temp;
    temp =root;
    if(temp==NULL)
    {
        printf("No nodes in this list.\n");
    }
    else
    {
        printf("Your nodes Elements are: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}

void delete ()
{
    struct node* temp;
    int loc,len;
    printf("Enter loc to delete: ");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid Location.\n");
    }
    else if(loc==1)
    {
        temp=root;
        root=temp->link;
        //temp->link=NULL;
        free(temp);
    }
    else
    {
        struct node* p, *q;
        p=root;
        int i=1;
        while(i<loc-1)
        {
            p=p->link;
            i++;
        }
        q=p->link;
        p->link=q->link;
      //  q->link=NULL;
        free(q);
    }
}

void main()
{
    printf("\n\t\t\t\tLINKED LIST\n");
    printf("1. Insert a node.\n");
    printf("2. Insert a node at beginning.\n");
    printf("3. Insert a node at any position.\n");
    printf("4. Length.\n");
    printf("5. Delete.\n");
    printf("6. Display.\n");
    printf("7. Exit.\n");

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
            insert_begenning();
            break;
        case 3:
            insert_after();
            break;
        case 4:
            length();
            break;
        case 5:
            delete();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(1);

        }
    }
}
