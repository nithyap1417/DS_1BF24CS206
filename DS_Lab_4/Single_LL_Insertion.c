#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *newnode=NULL;
void insertAtBeginning()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    printf("\nElement %d is inserted at Beginning",newnode->data);
}
void insertAtEnd()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("Element inserted at End");
    }
    struct node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    printf("\nElement %d is inserted at End",newnode->data);
}
void insertAtPos()
{
    int pos=0;
    struct node *prev=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("\nEnter position: ");
    scanf("%d",&pos);
    struct node *temp=head;
    if(pos<1)
    {
        printf("\nEnter valid position");
    }
    if(pos==1)
    {
        newnode->next=head;
        head=newnode;
    }
    for(int i=1;i<(pos-1)&&temp!=NULL;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("\nInserted element %d at %dth position",newnode->data,pos);
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nNothing to display!!");
        return;
    }
    while(temp!=NULL)
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
        printf("\n------------Insertion of Linked List--------------");
        printf("\nEnter\n1:insert at beginning\n2:insert at end\n3:insert at position\n4:Displaying\n5:exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1: insertAtBeginning();
                    break;
            case 2: insertAtEnd();
                    break;
            case 3: insertAtPos();
                    break;
            case 4: display();
                    break;
            case 5: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=5);
}