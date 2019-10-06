#include <stdio.h>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int N,M;
int arr[51][51];
char st[51][51];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int main(void)
{
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char s[51];
		scanf("%s",s);
		for(int j=0;j<M;j++)
			st[i][j]=s[j];
	}
	int maxs=-1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(st[i][j]=='W')
				continue;
			memset(arr,-1,sizeof(arr));
			queue<pair<int,int> > qq;
			qq.push(make_pair(i,j));
			arr[i][j]=0;
			while(!qq.empty())
			{
				pair<int,int> pp=qq.front();
				qq.pop();
				int x=pp.first;
				int y=pp.second;

				for(int k=0;k<4;k++)
				{
					int ddx=x+dx[k];
					int ddy=y+dy[k];

					if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
						continue;
					if(st[ddx][ddy]=='L' && arr[ddx][ddy]==-1)
					{
						arr[ddx][ddy]=arr[x][y]+1;
						maxs=max(arr[ddx][ddy],maxs);
						qq.push(make_pair(ddx,ddy));
					}
				}
			}
		}	
	}
	printf("%d",maxs);
}
