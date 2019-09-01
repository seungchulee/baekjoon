#include <stdio.h>
#include <cstring>
#include <set>
using namespace std;
int N,M;
int arr[1001][1001];
int visit[1001][1001];
int v[1000000];
int cnt;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ind=2;

void DFS(int x, int y)
{
	visit[x][y]=1;
	arr[x][y]=ind;
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];

		if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
			continue;
		if(arr[ddx][ddy]==0 && visit[ddx][ddy]==0)
		{
			cnt++;
			DFS(ddx,ddy);
		}
	}		
}
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%1d",&arr[i][j]);
			if(arr[i][j]==1)
				arr[i][j]=-1;

		}
	}
	memset(visit,0,sizeof(visit));
	memset(v,0,sizeof(v));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==0 && visit[i][j]==0)
			{
				cnt=1;
				DFS(i,j);
				v[ind]=cnt;
				ind++;
			}
		}
	}
	int result[1001][1001]={0};
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]==-1)
			{
				int ret=0;
				set<int> ss;
				for(int x=0;x<4;x++)
				{

					int ddx=i+dx[x];
					int ddy=j+dy[x];

					if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
						continue;
					if(arr[ddx][ddy]!=-1)
					{
						ss.insert(arr[ddx][ddy]);
					}
					
				}
				set<int>::iterator iter;
				for(iter=ss.begin();iter!=ss.end();++iter)
				{
					ret+=v[*iter];
				}

				result[i][j]=ret+1;

				
			}
		}

	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			printf("%d",result[i][j]%10);
		}
		printf("\n");
	}



}
