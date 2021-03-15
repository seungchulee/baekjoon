#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;
typedef struct Node{
	int num;
	Node *left;
	Node *right;
}node;
node *tree[10001];
node *head=NULL;
void insert(node *ace)
{
	if(head==NULL)
	{
		head=ace;
		return;
	}
	node *newNode=head;
	while(1)
	{
		if(ace->num<newNode->num)
		{
			if(newNode->left==NULL)
			{
				newNode->left=ace;
				break;
			}
			else
				newNode=newNode->left;
		}
		else
		{
			if(newNode->right==NULL)
			{
				newNode->right=ace;
				break;
			}
			else
				newNode=newNode->right;
		}
	}
}
node *createNode(int a)
{
	node *newNode=(node*)malloc(sizeof(node));
	newNode->num=a;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
void postorder(node *start)
{
	if(start==NULL)
		return;
	postorder(start->left);
	postorder(start->right);
	printf("%d\n",start->num);
}
int make(char ch[])
{
	int len = strlen(ch)-1;
	int sum=0;
	for(int i=0;i<strlen(ch);i++)
	{
		sum*=10;
		sum+=ch[i]-'0';

	}
	return sum;
}
int main(void)
{
	int cnt=0;
	while(1)
	{

		char ch[10];	
		cin.getline(ch,10);
		int num = make(ch);
		if(cin.eof()==true)
			break;
		node *ace=createNode(num);

		insert(ace);

		//postorder(head);
		//printf("---\n");
	}
	postorder(head);	

}
