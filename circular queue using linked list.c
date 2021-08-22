#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
}*temp,*front=NULL,*rear=NULL,*newnode;
void enqueue()
{
    int x;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data : ");
    scanf("%d",&x);
    if(rear==NULL)
    {
        newnode->data=x;
        front=rear=newnode;
        rear->next=front;
        printf("\nInserted successfully\n");
    }
    else
    {
        newnode->data=x;
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
        printf("\nInserted successfully\n");
    }
}
void dequeue()
{

    if(rear==NULL&&front==NULL)
        printf("\nUnderflow\n");
    else if(front==rear)
    {
        temp=front;
        front=rear=NULL;
        printf("%d deleted successfully\n",temp->data);
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        rear->next=front;
        printf("%d deleted successfully\n",temp->data);
        free(temp);

    }
}
void display()
{
    if(front==NULL&&rear==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        temp=front;
        printf("\nThe elements in the queue:\n");
        while(temp->next!=front)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\t\tCIRCULAR QUEUE OPERATIONS\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
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
    }
}

