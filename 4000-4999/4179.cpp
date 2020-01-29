#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
char arr[1010][1010];
int N,M;
int f_i,f_j;
int j_i,j_j;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int visit[1010][1010];
int jihoon[1010][1010];
int main(void)
{
	scanf("%d %d",&N,&M);
	queue<pair<int,int> > qq;
	int cnt=0;
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<N;i++)
	{
		char st[1010];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			arr[i][j]=st[j];
			if(arr[i][j]=='F')
			{
				cnt++;
				qq.push(make_pair(i,j));
				visit[i][j]=0;
				arr[i][j]='.';
			}
			if(arr[i][j]=='J')
			{
				j_i=i;
				j_j=j;
				arr[i][j]='.';
			}
		}
	}

	while(!qq.empty())
	{
		pair<int,int> pp = qq.front();
		qq.pop();
		int x = pp.first;
		int y = pp.second;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(arr[ddx][ddy]=='#')
				continue;
			if(arr[ddx][ddy]=='.' && visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				qq.push(make_pair(ddx,ddy));
			}
		}
	}
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			printf("%2d ",visit[i][j]);
		printf("\n");
	}*/
	memset(jihoon,-1,sizeof(jihoon));
	queue<pair<int,int> > ji;
	ji.push(make_pair(j_i,j_j));
	jihoon[j_i][j_j]=0;
	while(!ji.empty())
	{
		pair<int,int> pp = ji.front();
		ji.pop();
		int x = pp.first;
		int y = pp.second;
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=M)
				continue;
			if(arr[ddx][ddy]=='#')
				continue;
			if(cnt==0)
			{
				if(arr[ddx][ddy]=='.' && jihoon[ddx][ddy]==-1)
				{
					jihoon[ddx][ddy]=jihoon[x][y]+1;
					ji.push(make_pair(ddx,ddy));
				}

			}
			else
			{
				if(arr[ddx][ddy]=='.' && jihoon[ddx][ddy]==-1 && visit[ddx][ddy]>jihoon[x][y]+1)
				{
					jihoon[ddx][ddy]=jihoon[x][y]+1;
					ji.push(make_pair(ddx,ddy));
				}

			}

		}

	}
	int mins = 10000000;
	for(int i=0;i<N;i++)
	{
		if(jihoon[i][0]!=-1)
		{
			mins = min(mins,jihoon[i][0]);
		}
		if(jihoon[i][M-1]!=-1)
		{
			mins=min(mins,jihoon[i][M-1]);
		}
	}
	for(int i=0;i<M;i++)
	{
		if(jihoon[0][i]!=-1)
		{
			mins=min(mins,jihoon[0][i]);
		}
		if(jihoon[N-1][i]!=-1)
		{
			mins=min(mins,jihoon[N-1][i]);
		}
	}
	if(mins==10000000)
		printf("IMPOSSIBLE");
	else
		printf("%d",mins+1);
}

