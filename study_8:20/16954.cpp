#include <stdio.h>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
char arr[9][9];
bool check[8][8][9];
int dx[9]={0,0,1,-1,1,-1,1,-1,0};
int dy[9]={1,-1,0,0,1,1,-1,-1,0};
int main(void)
{
	for(int i=0;i<8;i++)
	{
		char st[9];
		scanf("%s",st);

		for(int j=0;j<8;j++)
		{
			arr[i][j]=st[j];
		}
	}
	queue<tuple<int,int,int>> qq;
	check[7][0][0]=true;
	qq.push(make_tuple(7,0,0));

	bool result=false;
	while(!qq.empty())
	{
		int x,y,t;
		tie(x,y,t)=qq.front();
		//printf("%d %d %d\n",x,y,t);
		qq.pop();
		if(x==0 && y==7)
			result=true;
		for(int i=0;i<9;i++)
		{
			int ddx=x+dx[i];
			int ddy=y+dy[i];
			int ddt=min(t+1,8);
			if(ddx<0 || ddy<0 || ddx>=8 || ddy>=8)
			{
				continue;
			}
			if(ddx-t>=0 && arr[ddx-t][ddy]=='#')
				continue;
			if(ddx-t-1>=0 && arr[ddx-t-1][ddy]=='#')
				continue;
			if(check[ddx][ddy][ddt]==false)
			{
				check[ddx][ddy][ddt]=true;
				qq.push(make_tuple(ddx,ddy,ddt));
			}
		}
	}
	printf("%u",result);
}
	




