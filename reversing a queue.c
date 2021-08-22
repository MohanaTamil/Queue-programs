#include<stdio.h>
#include<stdlib.h>
#define N 50
int queue[50],stack[50];
int top=-1,front=-1,rear=-1;
void enqueue()
{
    if(rear==N-1)
    {
        printf("\nQueue overflow\n");
    }
    else
    { int x;
       printf("\nEnter the data: ");
       scanf("%d",&x);
       rear++;
       queue[rear]=x;
       printf("\n%d inserted successfully\n ",queue[rear]);
    }
}

void reverse()
{
    while(front!=rear)
    {
        front++;
        top++;
        stack[top]=queue[front];
    }
    while(top!=-1)
    {
        rear++;
        queue[rear]=stack[top];
        top--;
    }
}
void display()
{
    if(front==rear)
    {
        printf("\nQueue is empty\n");

    }
    else
    {
        int  i;
        printf("\nBefore reversing the order of the queue is:\n");
        for(i=front+1;i<=rear;i++)
            printf("%d\t",queue[i]);
        reverse();
        printf("\nThe reversed order of the queue is:\n");
        for(i=front+1;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}
int main()
{
    int choice,i=1;
    do{
            printf("\n\n\t\tReversing the queue\n");
    printf("\n\n1.Enqueue\n2.Display\n3.Exit\n\nEnter your  choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:enqueue();
        break;
        case 2:display();
        break;
        case 3:exit(0);
        break;
        default:printf("\nInvalid choice\n");
    }
    }while(choice!=0);
    return 0;
}
