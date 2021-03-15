#include <stdio.h>
int arr[201];
int route[1001];
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
	for(int i=1;i<=200;i++)
		arr[i]=i;
	int N;
	scanf("%d",&N);
	int M;
	scanf("%d",&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N;j++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				Union(i,j);
			}
		}
	}
	
	for(int i=0;i<M;i++)
		scanf("%d",&route[i]);
	bool check=true;
	for(int i=1;i<M;i++)
	{
		if(find(route[i])!=find(route[i-1]))
		{
			check=false;
			break;
		}

	}
	if(check==true)
		printf("YES");
	else
		printf("NO");

}
