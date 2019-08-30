#include <stdio.h>
#include <cstring>
int N;
char arr[101][101];
int visit[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int cnt_R=0;
int cnt_G=0;
int cnt_B=0;
int cnt_RG=0;
int cnt_BB=0;

void DFS(int x, int y,char ch)
{
	visit[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];

		if(ddx<0 || ddy<0 || ddx>=N || ddy>=N)
			continue;
		if(arr[ddx][ddy]==ch && visit[ddx][ddy]==0)
		{
			DFS(ddx,ddy,ch);
		}


	}
}
int main(void)
{
	memset(visit,0,sizeof(visit));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		char st[101];
		scanf("%s",st);
		for(int j=0;j<N;j++)
		{
			arr[i][j]=st[j];
		}
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='R' && visit[i][j]==0)
			{
				cnt_R++;
				DFS(i,j,'R');
			}
		}
	}

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='B' && visit[i][j]==0)
			{
				cnt_B++;
				DFS(i,j,'B');
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='G' && visit[i][j]==0)
			{
				cnt_G++;
				DFS(i,j,'G');
			}
		}
	}


	memset(visit,0,sizeof(visit));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='G')
				arr[i][j]='R';

		}

	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='R' && visit[i][j]==0)
			{
				cnt_RG++;
				DFS(i,j,'R');
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='B' && visit[i][j]==0)
			{
				cnt_BB++;
				DFS(i,j,'B');
			}
		}
	}
	printf("%d %d",cnt_R+cnt_G+cnt_B,cnt_RG+cnt_BB);
	
}	


