#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,g,r;
int arr[51][51];
int visit[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
vector<pair<int,int> > vv;
vector<int> gg;
vector<int> rr;
int maxs=-1;
void permur()
{
	rr.clear();
	for(int i=0;i<vv.size()-r;i++)
		rr.push_back(0);
	for(int i=0;i<r;i++)
		rr.push_back(1);
	do{
		bool check=true;
		for(int i=0;i<gg.size();i++)
		{
			if(gg[i]==1)
			{
				if(rr[i]==1)
					check=false;
			}
		}
		if(check==false)
			continue;
		int arr2[51][51];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				arr2[i][j]=arr[i][j];
		memset(visit,-1,sizeof(visit));
		queue<pair<int,pair<int,int> > > q;
		for(int i=0;i<vv.size();i++)
		{
			if(gg[i]==1)
			{
				q.push(make_pair(3,make_pair(vv[i].first,vv[i].second)));
				visit[vv[i].first][vv[i].second]=0;
				arr2[vv[i].first][vv[i].second]=3;
			}
			if(rr[i]==1)
			{
				q.push(make_pair(4,make_pair(vv[i].first,vv[i].second)));
				visit[vv[i].first][vv[i].second]=0;
				arr2[vv[i].first][vv[i].second]=4;
			}
		}
		int cnt=0;
		while(!q.empty())
		{
			int type = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if(arr2[x][y]==5)
				continue;
			for(int i=0;i<4;i++)
			{
				int ddx = x+dx[i];
				int ddy = y+dy[i];
				if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
					continue;
				if(arr2[ddx][ddy]==0 || arr2[ddx][ddy]==5 || arr2[ddx][ddy]==type)
					continue;
				if(arr2[ddx][ddy]==1 || arr2[ddx][ddy]==2)
				{
					visit[ddx][ddy]=visit[x][y]+1;
					q.push(make_pair(type,make_pair(ddx,ddy)));
					arr2[ddx][ddy]=type;
				}
				else
				{
					if(visit[ddx][ddy]!=visit[x][y]+1)
						continue;
					arr2[ddx][ddy]=5;
					cnt++;

				}	
			}
		}
		maxs=max(cnt,maxs);
	}while(next_permutation(rr.begin(),rr.end()));
}
void permug()
{
	for(int i=0;i<vv.size()-g;i++)
		gg.push_back(0);
	for(int i=0;i<g;i++)
		gg.push_back(1);
	do{
		permur();
	}while(next_permutation(gg.begin(),gg.end()));
}
int main(void)
{
	cin >> n >> m >> g >> r;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
			if(arr[i][j]==2)
				vv.push_back(make_pair(i,j));
		}
	}
	permug();
	cout << maxs;
}
