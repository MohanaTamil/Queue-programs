#include<stdio.h>
#include<stdlib.h>
#define N 5
int dequeue[N];
int front=-1,rear=-1;
void isfull()
{
    if(front==0&&rear==N-1||front>rear)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        printf("\nQueue is not full\n");
    }
}
void isempty()
{
    if(front==-1)
        printf("\nQueue is empty\n");
}
void insertfront()
{
    int x;
    printf("\nEnter the data to insert: ");
  scanf("%d",&x);
  if((front==0&&rear==N-1)||front==rear+1)
  {
      printf("\nOverflow\n");
  }

  else if(front==-1&&rear==-1)
  {
      front=0;
      rear=0;
      dequeue[front]=x;
      printf("\nInserted element at front end\n");
  }
  else if(front==0)
  {
      front=N-1;
      dequeue[front]=x;
       printf("\nInserted element at front end\n");
  }
  else
  {
    front=front-1;
  dequeue[front]=x;
  printf("\nInserted element at front end\n");
}
}
void insertrear()
{
    int x;
    printf("\nEnter the data to insert: ");
  scanf("%d",&x);
   if((front==0&&rear==N-1)||front==rear+1)
   {
       printf("\nOverflow\n");
   }

   else if(front==-1&& rear==-1)
   {
       front=0;
       rear=0;
       dequeue[rear]=x;
       printf("\nInserted element at rear end\n");
   }
   else if(rear==N-1)
   {
       rear=0;
       dequeue[rear]=x;
       printf("\nInserted element at rear end\n");
   }
   else
   {
    rear=rear+1;
  dequeue[rear]=x;
  printf("\nInserted element at rear end\n");
   }
}
void deletefront()
{
   if(front==-1&&rear==-1)
   {
       printf("\nQueue underflow\n");
   }
   else if(front==rear)
   {
       front=-1;
       rear=-1;
        printf("\nDeleted sucessfully\n");
   }
   else
   {
       if(front==N-1)
        front=0;
       else
        front=front+1;
         printf("\nDeleted sucessfully\n");
   }
}
void deleterear()
{
   if(front==-1&&rear==-1)
   {
       printf("\nQueue underflow\n");
   }
   else if(front==rear)
   {
       front=-1;
       rear=-1;
       printf("\nDeleted sucessfully\n");
   }
   else if(rear==0)
   {
     rear=N-1;
      printf("\nDeleted sucessfully\n");
   }
   else
   {
    rear=rear-1;
     printf("\nDeleted sucessfully\n");
   }
}
void getfront()
{
   if((front==-1&&rear==-1)||front==rear+1)
   {
       printf("\nQueue is empty\n");
   }
   else
    printf("The get front element is : %d",dequeue[front]);
}
void getrear()
{
       if((front==-1&&rear==-1)||front==rear+1||rear<0)
   {
       printf("\nQueue underflow\n");
   }
   else
    printf("The get rear element is : %d",dequeue[rear]);

}

    void display()
    {
        int i=front;
        if(front==-1)
            printf("\nQueue is empty\n");
        else
        {
            printf("\nThe elements in the queue are: \n");
        while(i!=rear)
        {
            printf("%d\t",dequeue[i]);
            i=(i+1)%N;
        }
        printf("%d\t",dequeue[rear]);
        }
    }
int main()
{
    int choice;
    while(1)
    {
        printf("\n\n\tDequeue operations\n\n");
        printf("\n1.Isfull\n2.Isempty\n3.Insertfront\n4.Insertrear\n5.Deletefront\n6.Deleterear\n7.Getfront\n8.Getrear\n9.Exit\n10.Display\nEnter your choice:  ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:isfull();
            break;
            case 2:isempty();
            break;
            case 3:insertfront();
            break;
            case 4:insertrear();
            break;
            case 5:deletefront();
            break;
            case 6:deleterear();
            break;
            case 7:getfront();
            break;
            case 8:getrear();
            break;
            case 9:exit(1);
            break;
            case 10:display();
            break;
            default:printf("\nInvalid choice\n");
        }
    }
    return 0;
}
