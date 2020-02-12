#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
char arr[1001][1001];
int fire[1001][1001];
int man[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main(void)
{
	int t;
	scanf("%d",&t);
	for(int q=0;q<t;q++)
	{
		memset(fire,-1,sizeof(fire));
		memset(man,-1,sizeof(fire));
		int n,m;
		scanf("%d %d",&m,&n);
		queue<pair<int,int> > ff;
		queue<pair<int,int> > ss;
		for(int i=0;i<n;i++)
		{
			char st[1001];
			scanf("%s",st);

			for(int j=0;j<m;j++)
			{
				arr[i][j]=st[j];
				if(arr[i][j]=='*')
				{
					ff.push(make_pair(i,j));
					fire[i][j]=0;
				}
				if(arr[i][j]=='@')
				{
					ss.push(make_pair(i,j));
					man[i][j]=0;
				}
			}
		}
		while(!ff.empty())
		{
			int x = ff.front().first;
			int y = ff.front().second;
			ff.pop();
			for(int i=0;i<4;i++)
			{
				int ddx=  x+dx[i];
				int ddy = y+dy[i];
				if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
					continue;
				if(arr[ddx][ddy]!='#' && fire[ddx][ddy]==-1)
				{
					fire[ddx][ddy]=fire[x][y]+1;
					ff.push(make_pair(ddx,ddy));
				}
			}
		}	
		while(!ss.empty())
		{
			int x = ss.front().first;
			int y = ss.front().second;
			ss.pop();
			for(int i=0;i<4;i++)
			{
				int ddx = x+dx[i];
				int ddy = y+dy[i];
				if(ddx<0 || ddy<0 || ddx>=n || ddy>=m)
					continue;
				if(arr[ddx][ddy]!='#' && man[ddx][ddy]==-1 && (fire[ddx][ddy]>man[x][y]+1 || fire[ddx][ddy]==-1) )
				{
					man[ddx][ddy]=man[x][y]+1;
					ss.push(make_pair(ddx,ddy));
				}
			}
		}
		int mins=10000000;
		for(int i=0;i<n;i++)
		{	
			if(arr[i][0]!='#' && arr[i][0]!='*')
			{
				if(man[i][0]==-1)
					continue;
				mins=min(mins,man[i][0]);
			}
		}	
		for(int i=0;i<n;i++)
		{
			if(arr[i][m-1]!='#' && arr[i][m-1]!='*')
			{
				if(man[i][m-1]==-1)
					continue;
				mins=min(mins,man[i][m-1]);
			}
		}
		for(int j=0;j<m;j++)
		{
			if(arr[0][j]!='#' && arr[0][j]!='*')
			{
				if(man[0][j]==-1)
					continue;
				mins=min(mins,man[0][j]);
			}
		}
		for(int j=0;j<m;j++)
		{
			if(arr[n-1][j]!='#' && arr[n-1][j]!='*')
			{
				if(man[n-1][j]==-1)
					continue;
				mins=min(mins,man[n-1][j]);
			}
		}
		if(mins==10000000)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",mins+1);


	}
}
