#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
node *head = NULL;
node *rear=NULL;
void show_queue()
{
	node *now = (node*)malloc(sizeof(node));
	now=head;
	while(1)
	{
		printf("%d ",now->data);
		if(now->next==NULL)
			break;
		now=now->next;
	}
}
void enqueue(int n)
{
	node *now = (node*)malloc(sizeof(node));
	now->data=n;
	now->next=NULL;
	if(head==NULL)
	{
		head=now;
		
		rear=now;
	}
	else
	{
		rear->next=now;
		rear=rear->next;
	}
}
int main(void)
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		else if(n==-1)
			show_queue();
		else
		{
			enqueue(n);
		}
	}
	
}
