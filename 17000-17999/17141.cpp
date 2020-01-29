#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;
vector<pair<int,int> > vv;
int arr[51][51];
int visit[51][51];
int choice[11];
int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int mins = 10000000;
void get(vector<int> virus)
{
	int tmp[51][51];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			tmp[i][j]=arr[i][j];
			if(tmp[i][j]==2)
			{
				tmp[i][j]=0;
			}
			else if(tmp[i][j]==1)
				tmp[i][j]=-1;
		}
	}
	queue<pair<int,int> > qq;
	memset(visit,-1,sizeof(visit));
	for(int i=0;i<virus.size();i++)
	{
		int x = vv[virus[i]].first;
		int y = vv[virus[i]].second;
		tmp[x][y]=2;
		qq.push(make_pair(x,y));
		visit[x][y]=0;
	}
	int maxs=0;
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
			if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
				continue;
			if(tmp[ddx][ddy]==0 && visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				maxs=max(maxs,visit[ddx][ddy]);
				qq.push(make_pair(ddx,ddy));
			}
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(visit[i][j]==-1 && tmp[i][j]==0)
				return;

		}

	}

	mins = min(mins,maxs);
}
void func(int index, int cnt)
{
	if(cnt==M)
	{
		vector<int> virus;
		for(int i=0;i<vv.size();i++)
		{
			if(choice[i]==1)
				virus.push_back(i);
		}
		get(virus);		
		return;
	}

	for(int i=index;i<vv.size();i++)
	{
		if(choice[i]==1)
			continue;
		choice[i]=1;
		func(index+1,cnt+1);
		choice[i]=0;
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	memset(choice,0,sizeof(choice));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==2)
			{
				vv.push_back(make_pair(i,j));
			}
		}
	}
	func(0,0);
	if(mins==10000000)
		printf("-1");
	else
		printf("%d",mins);

}
