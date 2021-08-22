#include<stdio.h>
#include<stdlib.h>
#define N 50
int queue[N];
int front=-1,rear=-1;
void enqueue()
{
    if(rear==N-1)
        printf("\nQueue overflow\n");
    else
    {
        if(rear==-1&&front==-1)
        {
            front=0;
            rear=0;
        }
        else
           rear++;

       int x;
       printf("\nEnter the data: ");
       scanf("%d",&x);
      queue[rear]=x;
      printf("\n%d is inserted successfully\n",x);
    }
}
void dequeue()
{
   if(front==-1||front>rear)
    printf("\nQueue underflow\n");
   else
   {
       int x;
       x=queue[front];
       if(front==rear)
       {
           front=-1;
           rear=-1;
       }
       else
       front++;

       printf("\n%d is deleted successfully\n",x);
   }
}
void display()
{
    if(rear==-1)
        printf("\nQueue is empty");
    else
    {
        int i;
        printf("\nThe elements in the queue are:\n");
        for(i=front;i<=rear;i++)
            printf("%d\t",queue[i]);
    }
}
int main()
{
    int choice;
    do{
printf("\n\t\t\tQueue OPERATIONS\n");
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
scanf("%d",&choice);
switch(choice)
{
    case 1:enqueue();
    break;
    case 2:dequeue();
    break;
    case 3:display();
    break;
    case 4:exit(1);
    break;
    default:printf("\nInvalid choice\n");
}
    }while(choice!=0);
    return 0;
}
