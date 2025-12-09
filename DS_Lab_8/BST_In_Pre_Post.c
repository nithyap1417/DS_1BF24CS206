#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insertNode(struct node *root, int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    else if(value<root->data)
    {
        root->left=insertNode(root->left,value);
    }
    else if(value>root->data)
    {
        root->right=insertNode(root->right,value);
    }
    return root;
}

struct node* Inorder(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Inorder(root->left);
    printf(" %d ",root->data);
    Inorder(root->right);
    return root;
}

struct node* Preorder(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    printf(" %d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
    return root;
}

struct node* Postorder(struct node* root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Postorder(root->left);
    Postorder(root->right);
    printf(" %d ",root->data);
    return root;
}

void display(struct node* root)
{
    printf("\nElements in BST:");
    Inorder(root);
    printf("\n");
}

int main()
{               
    int x;
    struct node* root=NULL;
    printf("\n------------BINARY SEARCH TREE--------------");
    printf("\nEnter\n1:Insert value\n2:Inorder\n3:Preorder\n4:Postorder\n5:Display\n6:exit\n");
    do
    {
        scanf("%d",&x);
        switch(x)
        {
            int value;
            case 1: printf("Enter value: ");
                    scanf("%d",&value);
                    root=insertNode(root,value);
                    break;
            case 2: printf("Inorder:");
                    Inorder(root);
                    printf("\n");
                    break;
            case 3: printf("\nPreorder:");
                    Preorder(root);
                    printf("\n");
                    break;
            case 4: printf("\nPostorder:");
                    Postorder(root);
                    printf("\n");
                    break;
            case 5: display(root);
                    break;
            case 6: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=6);
}
