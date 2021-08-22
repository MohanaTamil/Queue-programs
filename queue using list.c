#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
    int data;
    struct node *next;
}*front,*rear,*newnode,*temp,*head;
void enqueue()
{
    int x;
    printf("\nEnter the data: ");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;

    if(front==NULL)
    {
      front=newnode;
      rear=newnode;
      front->next=NULL;
      rear->next=NULL;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=NULL;
    }
}
void dequeue()
{
if(front==NULL)
{
    printf("\nUnerflow\n");
}
else
    {
    temp=front;
     front=front->next;
     printf("%d is deleted successfully\n",temp->data);
     free(temp);
}
}
void display()
{
    if(front==NULL)
        printf("Queue is empty");
    else
        {
        temp=front;
        printf("\nThe elements in the queue:\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
int choice;
while(1)
{
    printf("\n\n\t\tQueue operations\n");
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
return 0;
}
