#include <stdio.h>
int arr[100011];
int find(int a)
{
	if(arr[a]==a)
		return a;
	else
		return arr[a]=find(arr[a]);
}
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa]=bb;
}
int main(void)
{

	int g,p;
	scanf("%d",&g);
	for(int i=1;i<=g;i++)
		arr[i]=i;
	scanf("%d",&p);
	int cnt=0;
	for(int i=0;i<p;i++)
	{
		int x;
		scanf("%d",&x);
		int xx = find(x);
		if(xx!=0)
		{
			Union(xx,xx-1);
			cnt++;
		}
		else
			break;
	}
	printf("%d",cnt);
}

