#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
int arr[11][11];
int visit[11][11];

int N;
int mins=10000000;
queue<pair<int,int> > qq;
void func(int index)
{
	if(index==3)
	{
		int new_visit[11][11];
		memset(new_visit,0,sizeof(new_visit));
		
		int result=0;
		for(int i=1;i<N-1;i++)
		{
			for(int j=1;j<N-1;j++)
			{
				if(visit[i][j]==1)
				{
					result+=arr[i][j];
					new_visit[i][j]=1;
					result+=arr[i-1][j];
					new_visit[i-1][j]=1;
					result+=arr[i+1][j];
					new_visit[i+1][j]=1;
					result+=arr[i][j+1];
					new_visit[i][j+1]=1;
					result+=arr[i][j-1];
					new_visit[i][j-1]=1;
				}
			}
		}
		int cnt=0;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(new_visit[i][j]==1)
				{
					cnt++;
				}
			}
		}

		if(cnt==15)
		{
			mins=min(mins,result);
		}

		return;
	}
	for(int i=1;i<N-1;i++)
	{
		for(int j=1;j<N-1;j++)
		{
			if(visit[i][j]==0)
			{
				visit[i][j]=1;
				func(index+1);
				visit[i][j]=0;
			}
		}
	}

}
int main(void)
{
	scanf("%d",&N);
	memset(visit,0,sizeof(visit));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	func(0);
	printf("%d",mins);
}

