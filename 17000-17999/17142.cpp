#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
vector<pair<int,int> > vv;
int arr[51][51];
int visit[51][51];
int choice[11];
int N,M;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int mins = 10000000;
int cntt=0;
void get(vector<int> virus)
{

	int cnt=cntt;
	queue<pair<int,int> > qq;
	memset(visit,-1,sizeof(visit));

	for(int i=0;i<virus.size();i++)
	{
		int x = vv[virus[i]].first;
		int y = vv[virus[i]].second;
		visit[x][y]=0;
		qq.push(make_pair(x,y));
		arr[x][y]=3;
		cnt--;
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
			if(arr[ddx][ddy]==-1)
				continue;
			if(arr[ddx][ddy]==0 && visit[ddx][ddy]==-1)
			{
				cnt--;
				visit[ddx][ddy]=visit[x][y]+1;
				maxs=max(maxs,visit[ddx][ddy]);
				qq.push(make_pair(ddx,ddy));
			}
			if(arr[ddx][ddy]==2 && visit[ddx][ddy]==-1)
			{
				cnt--;
				visit[ddx][ddy]=visit[x][y]+1;

				qq.push(make_pair(ddx,ddy));
			}

		}

	}


	for(int i=0;i<virus.size();i++)
	{
		int x = vv[virus[i]].first;
		int y = vv[virus[i]].second;
		arr[x][y]=2;
	}


	if(cnt!=0)
		return;

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
void funcc()
{
	vector<int> vs;
	for(int i=0;i<vv.size()-M;i++)
		vs.push_back(0);
	for(int i=0;i<M;i++)
		vs.push_back(1);
	do{
		vector<int> virus;
		for(int i=0;i<vs.size();i++)
		{
			if(vs[i]==1)
				virus.push_back(i);
		}
		get(virus);
	}while(next_permutation(vs.begin(),vs.end()));
}
int main(void)
{
	memset(arr,0,sizeof(arr));
	scanf("%d %d",&N,&M);
	memset(choice,0,sizeof(choice));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==0 || arr[i][j]==2)
				cntt++;
			if(arr[i][j]==2)
			{
				vv.push_back(make_pair(i,j));
			}
		}
	}
	funcc();
	if(mins==10000000)
		printf("-1");
	else
		printf("%d",mins);

}
