#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int visit[13];
vector<pair<int,int> > vv;
int mins=100000000;
int aa=0;
void func(int cnt,int idx)
{
	if(idx==n+1)
	{
		visit[n+1]=n+1;
		if(visit[0]==0 && visit[n+1]==n+1)
		{
			int summ=0;

			for(int i=0;i<n+1;i++)
				summ+=abs(vv[visit[i]].first-vv[visit[i+1]].first)+abs(vv[visit[i]].second-vv[visit[i+1]].second);
			mins=min(mins,summ);
		}
		return;
	}
	for(int i=1;i<n+1;i++)
	{
		if(visit[i]==-1)
		{
			visit[i]=idx;
			func(cnt+1,idx+1);
			visit[i]=-1;
		}
	}
}
int main(void)
{
	int t;
	cin >> t;
	for(int q=1;q<=t;q++)
	{
		cin >> n;
		mins=100000000;
		vv.clear();
		memset(visit,-1,sizeof(visit));
		for(int i=0;i<n+2;i++)
		{
			int x,y;
			cin >> x >> y;
			vv.push_back(make_pair(x,y));
		}	
		int xx = vv[1].first;
		int yy = vv[1].second;
		for(int i=1;i<n+1;i++)
		{
			vv[i].first=vv[i+1].first;
			vv[i].second=vv[i+1].second;
		}
		vv[n+1].first=xx;
		vv[n+1].second=yy;
		visit[0]=0;
		func(0,1);

		printf("#%d %d\n",q,mins);
	}
}
