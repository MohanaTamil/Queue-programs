#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define n 5
int stack1[n],stack2[n];
int top1=-1,top2=-1;
int count=0;

void enqueue();
void dequeue();
void push1();
int pop1();
void push2();
int pop2();
void display();
void main()
{
	int choice;
	do{
		printf("\nEnter your choice: \n1.Enqueue\n2.Dequeue\n3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enqueue();
			break;
				case 2:dequeue();
			break;
			case 3:display();
			break;
			default:printf("\nInvalid operation\n");
		}
	}while(choice!=0);
}
void enqueue()
{
	int x;
	printf("\nEnter data: ");
	scanf("%d",&x);
	 push1(x);
	 count++;	
}
void dequeue()
{
	int i,a,b;
	if(top1==-1&&top2==-1)
	printf("\nqueue is empty\n");
	else
	{
		for(i=0;i<count;i++)
   {
	a=pop1();
	push2(a);
	}
	b=pop2();
	printf("%d",b);
	count--;
	for(i=0;i<count;i++)
	{
		a=pop2();
		push1(a);
	}
	}
}
void push1(x)
{

	if(top1==n-1)
	printf("\nOverflow\n");
	else 
	{
	top1++;
	stack1[top1]=x;
   }
}
void push2(x)
{

	if(top2==n-1)
	printf("\nOverflow\n");
	else 
	{
	top2++;
	stack2[top2]=x;
   }
}
int pop1()
{
	int result;
	if(top1==-1)
	printf("\nUnderflow\n");
	else
	result=stack1[top1--];
	return result;
}
int pop2()
{
	int result;
	if(top2==-1)
	printf("\nUnderflow\n");
	else
	 result=stack2[top2--];
	 return result;
}
void display()
{
	int i;
	if(top1==-1)
	printf("\nQueue is empty\n");
	else
	{
	
	printf("\nThe elements in the queue:\n");
	for(i=0;i<=top1;i++)
	{
		printf("%d\t",stack1[i]);
	}
}
}
