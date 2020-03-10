#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char arr[51][51];
int visit[64][51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int main(void)
{
	cin >> n >> m;
	int sx,sy;
	for(int i=0;i<n;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<m;j++)
		{
			arr[i][j]=st[j];
			if(arr[i][j]=='0')
			{
				sx=i;
				sy=j;
			}
		}
	}
	memset(visit,-1,sizeof(visit));
	queue<pair<pair<int,int>,pair<int,int> > > qq;
	qq.push(make_pair(make_pair(sx,sy),make_pair(0,0)));
	visit[0][sx][sy]=1;
	while(!qq.empty())
	{
		int x = qq.front().first.first;
		int y = qq.front().first.second;
		int cnt = qq.front().second.first;
		int key = qq.front().second.second;
		qq.pop();
		if(arr[x][y]=='1')
		{
			printf("%d",cnt);
			return 0;
		}
		for(int i=0;i<4;i++)
		{
			int ddx = x+dx[i];
			int ddy = y+dy[i];
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;
			if(arr[ddx][ddy]=='#')
				continue;
			if(visit[key][ddx][ddy]==1)
				continue;
			if(arr[ddx][ddy]=='.' || arr[ddx][ddy]=='1' || arr[ddx][ddy]=='0')
			{
				visit[key][ddx][ddy]=1;
				qq.push(make_pair(make_pair(ddx,ddy),make_pair(cnt+1,key)));
			}
			else if(arr[ddx][ddy]>='a' && arr[ddx][ddy]<='f')
			{
				int newkey = key | (1 << (arr[ddx][ddy]-'a'));
				visit[key][ddx][ddy]=1;
				visit[newkey][ddx][ddy]=1;
				qq.push(make_pair(make_pair(ddx,ddy),make_pair(cnt+1,newkey)));
			}
			else if(arr[ddx][ddy]>='A' && arr[ddx][ddy]<='F')
			{
				if(key & (1 << (arr[ddx][ddy]-'A')))
				{
					visit[key][ddx][ddy]=1;
					qq.push(make_pair(make_pair(ddx,ddy),make_pair(cnt+1,key)));
				}
			}

		}
	}
	printf("-1");
}
