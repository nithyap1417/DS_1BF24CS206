#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode=NULL;
struct node *head=NULL;
struct node *tail=NULL;

struct node* createNewNode()
{
    int value;
    printf("Enter Data: ");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void insertAtBeginning()
{
    createNewNode();
    if(head==NULL && tail==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    printf("\nInserted element %d",newnode->data);
}

void insertAtPOS()
{
    int POS;
    printf("Enter the position to insert the value: ");
    scanf("%d",&POS);
    if(POS==1)
    {
        insertAtBeginning();
    }
    else
    {
        createNewNode();
        struct node* temp=head;
        for(int i=1;i<=(POS-1);i++)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        printf("\nInserted element %d at Position %d",newnode->data,POS);
    }
}

void insertAtPrePOS()
{
    int POS;
    printf("Enter the position to insert the value: ");
    scanf("%d",&POS);
     if(POS==2)
    {
        insertAtBeginning();
    }
    else
    {
        createNewNode();
        struct node* temp=head;
        for(int i=1;i<(POS-1);i++)
        {
            temp=temp->next;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp->next->prev=newnode;
        printf("\nInserted element %d at Position %d",newnode->data,POS);
    }
}

void deleteAtValue()
{
    int value;
    printf("\nEnter value to be deleted: ");
    scanf("%d",&value);
    struct node* temp=head;
    while(temp->data!=value)
    {
        temp=temp->next;
    }
    printf("\nDeleted element %d",temp->data);
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void deleteAtPOS()
{
    int POS;
    printf("\nEnter Position to be deleted: ");
    scanf("%d",&POS);
    struct node* temp=head;
    for(int i=1;i<=(POS-1);i++)
    {
        temp=temp->next;
    }
    printf("\nDeleted element %d",temp->data);
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void display()
{
    struct node* temp=head;
    while(temp!=tail)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}

int main()
{               
    int x;
    do
    {
        printf("\n------------Operations on Doubly Linked List--------------");
        printf("\nEnter\n1:Create Linked List\n2:Insert At Beginning\n3:Delete By Value\n4:Display\n5:exit\n");
        scanf("%d",&x);
        switch(x)
        {
            int value;
            case 1: createNewNode();
                    break;
            case 2: insertAtBeginning();
                    break;
            case 3: deleteAtValue();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=5);
}
