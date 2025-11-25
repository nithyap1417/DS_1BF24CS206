#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* createLinkedList()
{
    struct node *head=NULL;
    struct node *newnode=NULL;
    struct node *temp=NULL;
    int n;
    printf("\nEnter Number of elements: ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter Element[%d] Data: ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        temp->next=newnode;
        temp=newnode;
    }
    return head;
}

void displayLinkedList(struct node *head)
{
    struct node *i=NULL;
    printf("\n");
    for(i=head;i!=NULL;i=i->next)
    {
        printf("%d->",i->data);
    }
    printf("NULL");
}

struct node* sortLinkedList(struct node *head)
{
    struct node *i=NULL;
    struct node *j=NULL;
    int tempData=0;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data>j->data)
            {
                tempData=i->data;
                i->data=j->data;
                j->data=tempData;
            }
        }
    }
    displayLinkedList(head);
    return head;
}

struct node* reverseLinkedList(struct node *head)
{
    struct node *curr=head;
    struct node *temp=NULL;
    struct node *prev=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    displayLinkedList(head);
    return head;
}

struct node* concatLinkedLists(struct node *head1, struct node *head2)
{
    struct node *temp=head1;
    if(head1==NULL)
    {
        return head2;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    displayLinkedList(head1);
    return head1;
}

int main()
{               
    int x;
    do
    {
        printf("\n------------Operations on Linked List--------------");
        printf("\nEnter\n1:Create Linked List\n2:Sort Linked List\n3:Reverse Linked List\n4:Concatinate Linked Lists\n5:exit\n");
        scanf("%d",&x);
        struct node *head1;
        struct node *head2;
        switch(x)
        {
            case 1: head1=createLinkedList();
                    break;
            case 2: sortLinkedList(head1);
                    break;
            case 3: reverseLinkedList(head1);
                    break;
            case 4: head2=createLinkedList();
                    concatLinkedLists(head1,head2);
                    break;
            case 5: printf("\nExit");
                    break;
            default: printf("\nEnter Valid value");

        }
    }while (x!=5);
}