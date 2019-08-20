#include <stdio.h>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
int dist[1001][1001];
int S;
queue<pair<int,int> > qq;
int main(void)
{
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			dist[i][j]=-1;
		}
	}

	scanf("%d",&S);
	dist[1][0]=0;
	pair <int,int> r = make_pair(1,0);
	qq.push(r);
	while(!qq.empty())
	{
		pair <int,int> q =qq.front();
		qq.pop();
		int now=q.first;
		int save=q.second;

		if(now>=1)
		{
			if(dist[now][now]==-1)
			{

				pair <int,int> s = make_pair(now,now);
				qq.push(s);
				dist[now][now]=dist[now][save]+1;
			}

		}
		if(now+save<=1000 && save>0)
		{
			if(dist[now+save][save]==-1)
			{
				pair <int,int> s = make_pair(now+save,save);
				qq.push(s);
				dist[now+save][save]=dist[now][save]+1;
			}
		}
		if(now-1>=0)
		{
			if(dist[now-1][save]==-1)
			{
				pair <int,int> s = make_pair(now-1,save);
				qq.push(s);
				dist[now-1][save]=dist[now][save]+1;
			}
		}
	}
	int mins=1000000;
	for(int i=0;i<=1000;i++)
	{
		if(dist[S][i]==-1)
			continue;
		mins=min(mins,dist[S][i]);
	}
	if(mins==1000000)
		mins=-1;
	printf("%d",mins);

	

}
