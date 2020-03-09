#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
int visit[101][101];
int main(void)
{
	for(int a=1;a<=10;a++)
	{
		int q;

		cin >> q;
		int sx,sy;
		int ex,ey;
		memset(visit,-1,sizeof(visit));
		for(int i=0;i<100;i++)
		{
			for(int j=0;j<100;j++)
			{
				scanf("%1d",&arr[i][j]);
				if(arr[i][j]==2)
				{
					sx=i;
					sy=j;
				}
				if(arr[i][j]==3)
				{
					ex=i;ey=j;
				}
			}
		}
		queue<pair<int,int> > qq;
		qq.push(make_pair(sx,sy));
		visit[sx][sy]=1;
		while(!qq.empty())
		{
			int x = qq.front().first;
			int y = qq.front().second;
			qq.pop();
			for(int i=0;i<4;i++)
			{
				int ddx = x+dx[i];
				int ddy = y+dy[i];
				if(ddx<0 || ddy<0 || ddx>=100 || ddy>=100)
					continue;
				if(visit[ddx][ddy]==-1 && arr[ddx][ddy]!=1)
				{
					qq.push(make_pair(ddx,ddy));
					visit[ddx][ddy]=1;
				}
			}
		}
		if(visit[ex][ey]==-1)
			printf("#%d 0\n",a);
		else 
			printf("#%d 1\n",a);

	}	
}
