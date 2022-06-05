#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* left;
    int data;
    struct node* right;
};
struct node *root  =NULL;

//struct node* newNode(int data)
struct node* create(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ",node->data);
    printInorder(node->right);
}
void printPreorder(struct node* node)
{
    if (node == NULL)
    return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}
int main()
{
    root               = create(2);
    root->left         = create(3);
    root->right        = create(1);
    root->left->left   = create(7);
    root->left->right  = create(9);
    printf("\nPre-Order \n");
    printPreorder(root);
    printf("\n\nIn-Order \n");
    printInorder(root);
    printf("\n\nPost-Order \n");
    printPostorder(root);
    return 0;
}
