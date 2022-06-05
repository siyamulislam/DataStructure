#include<stdio.h>
int main()
{
    int n,e,i,j;
    printf("Enter the number of Node: ");
    scanf("%d",&n);
    printf("Enter the number of Edges: ");
    scanf("%d",&e);
    int graph[n][n], n1[e], n2[e];
    printf("Enter the pairs of nodes that are connected by edges:\n");
    for(i=0; i<e; i++)
    {
        printf("Pair %d. ",i+1);
        scanf("%d %d", &n1[i],&n2[i]);
    }

    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
        {
            if( n1[i]== graph[i] && n2[j]== graph[j] )
            {
                graph[i][j]=1;
            }
             else graph[i][j]=0;
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    return 0;
}
