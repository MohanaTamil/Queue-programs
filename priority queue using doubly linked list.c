#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int priority;
    struct node *next;
    struct node *previous;
}*temp,*newnode,*front,*rear;
void enqueue()
{
    int x,pr;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data:  ");
    scanf("%d",&x);
    printf("\nEnter the priority:  ");
    scanf("%d",&pr);
    newnode->data=x;
    newnode->priority=pr;
    newnode->previous=NULL;
    newnode->next=NULL;
    if(front==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
        temp=front;
     if(pr<=front->priority)
     {
         newnode->next=front;
         front=newnode;
         front->previous=NULL;
     }
     else if(pr>rear->priority)
     {
         rear->next=newnode;
         newnode->previous=rear->next;
         rear=newnode;
         rear->next=NULL;
     }
     else
    {
      while(temp->next!=NULL&&temp->next->priority<pr)
      {
          temp=temp->next;
      }
      newnode->next=temp->next;
      temp->next->previous=newnode;
      newnode->previous=temp;
      temp->next=newnode;
     }
    }
}
void dequeue()
{
    temp=front;
    int x=front->data;
    int y=front->priority;
    printf("\nThe least priority element deleted is :  %d\n",x);
    front=front->next;
    front->previous=NULL;
    free(temp);
    if(front==NULL)
        rear==NULL;
}
void display()
{
    if(front==NULL)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
      temp=front;
     printf("\nThe elements based on their priority: \n");
     while(temp!=NULL)
     {
         printf("%d-------->%d\n",temp->data,temp->priority);
         temp=temp->next;
     }
    }
}
void peek()
{
    printf("\nThe top of the element is:  %d",front->data);
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\t\tPRIORITY QUEUE\n");
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\nEnter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:display();
            break;
            case 4:peek();
            break;
            case 5:exit(1);
            break;
            default:printf("\nInvalid choice\n");
        }
    }
    return 0;
}

