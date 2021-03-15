#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char num;
	Node *left;
	Node *right;
}node;
int N;
node *createNode(char a)
{
	node *newNode = (node*)malloc(sizeof(node));
	newNode->num = a;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
node *tree[27];
void preorder(node *data)
{
	if (data == NULL)
		return;

	printf("%c", data->num);
	preorder(data->left);
	preorder(data->right);
}
void postorder(node *data)
{
	if (data == NULL)
		return;
	postorder(data->left);
	postorder(data->right);
	printf("%c", data->num);
}
void inorder(node *data)
{
	if (data == NULL)
		return;
	inorder(data->left);
	printf("%c", data->num);
	inorder(data->right);
}
int main(void)
{
	scanf("%d", &N);
	char arr[27][2];
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		getchar();
		scanf("%c %c %c", &a, &b, &c);
		arr[i][0] = b; arr[i][1] = c;
		tree[i] = createNode(a);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (tree[j]->num == arr[i][0])
			{
				tree[i]->left = tree[j];
			}
			if (tree[j]->num == arr[i][1])
			{
				tree[i]->right = tree[j];
			}
		}
	}
	preorder(tree[0]);
	printf("\n");
	inorder(tree[0]);
	printf("\n");
	postorder(tree[0]);
}
