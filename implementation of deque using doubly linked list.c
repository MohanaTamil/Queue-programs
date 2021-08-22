#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *prev;
struct node *next;
}*front,*rear,*temp,*newnode;
int size=0;
void insertatfront()
{
    int x;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data to insert:  ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(newnode==NULL)
        printf("\nOverflow\n");
    else
    {
        if(front==NULL)
          front=rear=newnode;
        else
        {
          newnode->next=front;
          front->prev=newnode;
          front=newnode;
         }
         size++;
         printf("\nElement inserted successfully\n");
    }
}
void insertatrear()
{
    int x;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("\nEnter the data to insert:  ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(newnode==NULL)
        printf("\nOverflow\n");
    else
    {
        if(rear==NULL)
            front=rear=newnode;
        else
        {
            newnode->prev=rear;
            rear->next=newnode;
            rear=newnode;
        }
        size++;
        printf("\nElement inserted successfully\n");
    }
}
void deleteatfront()
{
    if(front==NULL)
        printf("\nUnderflow\n");
    else
    {
        temp=front;
        printf("\n%d deleted successfully\n",temp->data);
        front=front->next;
        if(front==NULL)
            rear==NULL;
        else
            front->prev=NULL;
        free(temp);
        size--;
    }
}
void deleteatrear()
{
    if(front==NULL)
        printf("\nUnderflow\n");
    else
    {
        temp=rear;
        rear=rear->prev;
        if(rear==NULL)
            front=NULL;
        else
            rear->next=NULL;
        printf("\n%d deleted successfully\n",temp->data);
        free(temp);
        size--;

    }
}
void isempty()
{
    if(front==NULL)
        printf("\nQueue is empty\n");
    else
        printf("\nThere is element in the queue\n");
}
void length()
{
    printf("\nThe size of the queue is : %d\n",size);
}
void display()
{
    if(front==NULL)
        printf("\nQueue is empty\n");
    else
    {
        temp=front;
        printf("\nThe elements in the queue: \n\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}
void getfront()
{
    if(front==NULL)
        printf("\nThere is no element\n");
    else
    printf("\nThe front element is :  %d\n",front->data);
}
void getrear()
{
    if(rear==NULL)
        printf("\nThere is no element\n");
    else
        printf("\nThe rear element is :  %d\n",rear->data);
}
void erase()
{
    rear=NULL;
    while(front!=NULL)
    {
        temp=front;
        front=front->next;
        free(temp);
    }
    printf("\nDeleted all elements in the queue\n");
    size=0;
}
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\tDequeue operations\n\n");
        printf("\n1.Insertfront\n2.Insertrear\n3.Deletefront\n4.Deleterear\n5.Getfront\n6.Getrear\n7.Isempty \n8.Display\n9.Size\n10.Erase\n11.Exit\n\nEnter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {


            case 1:insertatfront();
            break;
            case 2:insertatrear();
            break;
            case 3:deleteatfront();
            break;
            case 4:deleteatrear();
            break;
            case 5:getfront();
            break;
            case 6:getrear();
            break;
            case 7:isempty();
            break;
            case 8:display();
            break;
            case 9:length();
            break;
            case 10:erase();
            break;
            case 11:exit(1);
            break;
            default:printf("\nInvalid choice\n");
        }
    }
    return 0;
}

