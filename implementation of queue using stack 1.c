#include <stdio.h>
#define n 5
int stack1[n], stack2[n];
int top1 = -1, top2 = -1;
int count = 0;


void enqueue ();
void dequeue ();
void push1 ();
void pop1 ();
void push2 ();
void pop2 ();
void display ();
void
main ()
{
  int choice;
  do
    {
      printf ("\nEnter your choice: \n1.Enqueue\n2.Dequeue\n3.Display\n");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  enqueue ();
	  break;
	case 2:
	  dequeue ();
	  break;
	case 3:
	  display ();
	  break;
	default:
	  printf ("\nInvalid operation\n");
	}
    }
  while (choice != 0);
}

void enqueue()
{
  int x;
  printf ("\nEnter the data: ");
  scanf ("%d", &x);
  if (top1 == n - 1)
    printf ("\nOverflow\n");
  else
    {
      top1++;
      stack1[top1] = x;
    }

}

void
dequeue ()
{
  int i, item;
  if (top1 == -1 )
    {
      printf ("\nQueue is empty\n");
    }
  else
    {
      while (top1 >= 0)
	{
	  top2++;
	  stack2[top2] = stack1[top1];
	  top1--;
	}
      item = stack2[top2];
      top2--;
      printf ("\nThe deleted element is %d", item);
      while (top2 >= 0)
	{
	  top1++;
	  stack1[top1] = stack2[top2];
	  top2--;
	}
    }
}

void
display ()
{
  int i;
  if (top1 == -1)
    printf ("\nQueue is empty\n");
  else
    {
        printf ("\nThe elements in the list are\n");
      for (i = top1; i >= 0; i--)
	{
	  printf ("%d\t", stack1[i]);

	}
    }
}

