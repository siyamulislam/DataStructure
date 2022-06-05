#include<stdio.h>
int i, n,arr[1000];
int end= -1;
void insert()
{
    printf("please input ur array\n");
    end++;
    scanf("%d", &n);
    arr[end]=n;
}
void print()
{
    printf("\nshowing ur arrr\n");
    for(i=0; i<=end; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void ins_position()
{
    end ++;
    int position, value;
    printf("Enter a position\n");
    scanf("%d", &position);
    printf("Enter a value\n");
    scanf("%d", &value);

    for(i=end; i>=position; i--)
    {
        arr[i]=arr[i-1];
        arr[position]=value;
    }
}
void deleting()
{
    int position;
    printf("Enter a position for deleting \n");
   scanf("%d", &position);


  for(i=position+1; i<=end; i++)
   {
        arr[i-1]= arr[i];
   }
   end--;
   /* i=position+1;
   while(i<=end)
   {
       arr[i-1]=arr[i];
       i++;
   }
   end--;*/
}

int main()
{
    while(1)
    {
        int n;

        printf("press 1 to input/insert\n");
        printf("press 2 to print the array\n");
        printf("press 3 to insert any position\n");
        printf("press 4 to delete\n");
        printf("press 5 to exit\n");

        scanf("%d",&n);

        if(n==1)
            insert();
        else if(n==2)
            print();
        else if(n==3)
            ins_position();
        else if(n==4)
            deleting();
        else if(n==5)
            break;
    }

    return 0;
}
