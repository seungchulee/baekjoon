#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int arr[51][51];
int brr[51];
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			arr[i][j]=10101010;
		}
	}
	while(1)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		if(x==-1 && y==-1)
			break;
		arr[x][y]=1;
		arr[y][x]=1;

	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(arr[i][j]>arr[i][k]+arr[k][j])
				{
					arr[i][j]=arr[i][k]+arr[k][j];
				}
				
			}
		}
	}
	int mins = 10000000;
	memset(brr,-1,sizeof(brr));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				continue;
			brr[i]=max(brr[i],arr[i][j]);
		}
		mins=min(mins,brr[i]);
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(brr[i]==mins)
			cnt++;
	printf("%d %d\n",mins,cnt);
	for(int i=1;i<=n;i++)
	{
		if(brr[i]==mins)
		{
			printf("%d ",i);
		}
	}
}
