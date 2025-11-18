#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
void createList(int n)
{
    struct node *newnode=NULL;
    struct node *temp1=head;
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        
        else
        {
            temp1->next=newnode;
        }
        temp1=newnode;
    
    }
    printf("\nLinked List Created!!");
}

void deleteFirst()
{
    struct node *temp2=NULL;
    if(head==NULL)
    {
        printf("\nNothing to Delete!!");
    }
    else if(head->next==NULL)
    {
        printf("\nDeleted %d",head->data);
        free(head);
    
    }
    else
    {
        temp2=head;
        head=head->next;
        printf("\nDeleted %d",temp2->data);
        free(temp2);
    }
    
}

void deleteLast()
{
    struct node *temp3=head;
    struct node *prev1=NULL;
    if(head==NULL)
    {
        printf("\nNothing to Delete!!");
    }
    else if(head->next==NULL)
    {
        printf("\nDeleted %d",head->data);
        free(head);
        head=NULL;
    }
    else
    {
        while(temp3->next!=NULL)
        {
            prev1=temp3;
            temp3=temp3->next;
        }
        prev1->next=NULL;
        printf("\nDeleted %d",temp3->data);
        free(temp3);
    }
}

void deleteAtPOS()
{
    struct node *temp4=head;
    struct node *prev2=NULL;
    int pos;
    printf("\nEnter Position of element to delete: ");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++)
    {
        prev2=temp4;
        temp4=temp4->next;
    }
    prev2->next=temp4->next;
    printf("\nDeleted %d",temp4->data);
    free(temp4);
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
        printf("\n------------Deleteion of Linked List--------------");
        printf("\nEnter\n1:Create a Linked List\n2:Delete at beginning\n3:Delete at end\n4:Delete at position\n5:Display\n6:exit\n");
        scanf("%d",&x);
        switch(x)
        {
            int n;
            case 1: printf("\nEnter Number of Elements: ");
                    scanf("%d",&n);
                    createList(n);
                    break;
            case 2: deleteFirst();
                    break;
            case 3: deleteLast();
                    break;
            case 4: deleteAtPOS();
                    break;
            case 5: display();
                    break;
            case 6: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=6);
}