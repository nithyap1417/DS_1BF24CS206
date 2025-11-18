#include<stdio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front=-1;
int rear=-1;
void enqueue(int x)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else if(rear==N-1)
    {
        printf("Queue overflow!!");
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW!!");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        printf("Element %d is deleted",queue[front]);
        front++;
    }
}
void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW, Nothing to Display");
    }
    else
    {
        for(int i=front;i<=rear;i++)
        {
            printf("\n%d",queue[i]);
        }
    }
}
int main()
{
    int j;
    do
    {
        printf("\nEnter\n1:Enqueue\n2:Dequeue\n3:Display\n4:Exit\nEnter Choice: ");
        scanf("%d",&j);
        switch(j)
        {
            int k;
            case 1: printf("Enter element: ");
            scanf("%d",&k);
            enqueue(k);
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            case 4: printf("Exit");
            break;
            default: printf("Invalud value");

        }
    }while(j!=4);
}
