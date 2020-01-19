#include <stdio.h>
#include <set>
#include <cstring>
#include <queue>
using namespace std;
int R,C;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char arr[21][21];
int visit[21][21];
int alpha[28];
int ans=-1;
void dfs(int x, int y,int cnt)
{
	ans=max(ans,cnt);
	
	
	for(int i=0;i<4;i++)
	{
		int ddx=x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=R || ddy>=C)
			continue;
		if(alpha[arr[ddx][ddy]-'A']==0)
		{
			alpha[arr[ddx][ddy]-'A']=1;
			dfs(ddx,ddy,cnt+1);
			alpha[arr[ddx][ddy]-'A']=0;
		//	cnt--;
		}
	}


}
int main(void)
{
	memset(visit,0,sizeof(visit));
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
	{
		char st[21];
		scanf("%s",st);
		for(int j=0;j<C;j++)
		{
			arr[i][j]=st[j];
		}
	}
	alpha[arr[0][0]-'A']=1;
	dfs(0,0,1);
	printf("%d",ans);
}	
