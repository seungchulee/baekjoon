#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>

#include <algorithm>
using namespace std;
int arr[3030][3030];
int visit[3030][3030];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(void)
{
	int n,m;
	memset(visit,-1,sizeof(visit));
	scanf("%d %d",&n,&m);
	int sx,sy;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			arr[i][j]=s[j]-'0';
			if(arr[i][j]==2)
			{
				sx=i;
				sy=j;
			}
		}
	}

	queue<pair<int,int> > qq;
	qq.push(make_pair(sx,sy));
	visit[sx][sy]=0;
	int mins=10000000;
	while(!qq.empty())
	{
		int x = qq.front().first;
		int y = qq.front().second;

		qq.pop();
		for(int i=0;i<4;i++)
		{
			int ddx = dx[i]+x;
			int ddy = dy[i]+y;
			if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
				continue;
			if(arr[ddx][ddy]!=1 && visit[ddx][ddy]==-1)
			{
				visit[ddx][ddy]=visit[x][y]+1;
				if(arr[ddx][ddy]>=3 && arr[ddx][ddy]<=5)
				{
					mins=min(mins,visit[ddx][ddy]);
					printf("TAK\n%d",mins);
					return 0;
				}
				qq.push(make_pair(ddx,ddy));
			}
		}
	}
	printf("NIE");		

}
