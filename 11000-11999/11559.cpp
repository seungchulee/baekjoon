#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
char field[15][15];
char visit[15][15];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt;
queue<pair<int,int> > qq;
void DFS(int x, int y,char ff)
{
	visit[x][y]=0;
	for(int k=0;k<4;k++)
	{
		int ddx=x+dx[k];
		int ddy=y+dy[k];
		if(ddx<0 || ddy<0 || ddx>=12 || ddy>=6)
		{
			continue;
		}
		if(visit[ddx][ddy]==-1 && field[ddx][ddy]==ff)
		{
			cnt++;
			qq.push(make_pair(ddx,ddy));
			DFS(ddx,ddy,ff);
		}
	}
}
void gravity()
{
	for(int j=0;j<6;j++)
	{
		int cnt=0;
		queue<char> gr;
		for(int i=11;i>=0;i--)
		{
			if(field[i][j]!='.')
			{
				cnt++;
				gr.push(field[i][j]);
				field[i][j]='.';
			}
		}
		if(cnt>0)
		{
			for(int i=11;i>11-cnt;i--)
			{
				char pushs=gr.front();
				gr.pop();
				field[i][j]=pushs;
			}
		}
	}
}
int find_four()
{
	memset(visit,-1,sizeof(visit));
	cnt=0;
	int kk=1;
	int exist=0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(visit[i][j]==-1)
			{
				cnt=1;
				qq.push(make_pair(i,j));
				DFS(i,j,field[i][j]);
				
				if(cnt>=4)
				{	
					if(field[i][j]!='.')
					{
						exist++;
						while(!qq.empty())
						{
							pair<int,int> pp=qq.front();
							qq.pop();
							int x=pp.first;
							int y=pp.second;
							field[x][y]='.';
						}
					}
				}
				else
				{
					while(!qq.empty())
					{
						qq.pop();
					}
				}
				//printf("%d : %d\n",kk,cnt);
				//kk++;
			}
		}
	}
	return exist;
}
int main(void)
{
	for(int i=0;i<12;i++)
	{
		char st[10];
		scanf("%s",st);
		for(int j=0;j<6;j++)
		{
			field[i][j]=st[j];
		}
	}
	int sol=0;
	while(1)
	{
		int result=find_four();
		if(result==0)
			break;
		sol++;
		//printf("%d",result);
		gravity();	
	}
	printf("%d",sol);
	
	/*for(int i=0;i<12;i++)
	{
		for(int j=0;j<6;j++)
		{
			printf("%c",field[i][j]);
		}
		printf("\n");
	}*/
}
