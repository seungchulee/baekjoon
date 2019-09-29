#include <stdio.h>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;
int arr[301][301];
int ddx[8]={-1,-2,-2,-1,1,2,2,1 };
int ddy[8]={-2,-1,1,2,2,1,-1,-2 };
int N;
int x1,y1;
int x2,y2;
void bfs()
{
	queue<pair<int,int> > qq;
	qq.push(make_pair(x1,y1));
	arr[x1][y1]=0;
	while(!qq.empty())
	{
		pair<int,int> pp=qq.front();
		qq.pop();
		int xx=pp.first;
		int yy=pp.second;
		if(xx==x2 && yy==y2)
			break;
		for(int i=0;i<8;i++)
		{
			int dx=xx+ddx[i];
			int dy=yy+ddy[i];
			if(dx>=0 && dy>=0 && dx<N && dy<N)
			{
				if(arr[dx][dy]==-1)
				{
					qq.push(make_pair(dx,dy));
					arr[dx][dy]=arr[xx][yy]+1;
				}
			}

		}
	}
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		memset(arr,-1,sizeof(arr));
		scanf("%d",&N);
		scanf("%d %d",&x1,&y1);
		scanf("%d %d",&x2,&y2);
		bfs();
		printf("%d\n",arr[x2][y2]);
	}
}
