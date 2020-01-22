#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
char arr[31][31][31];
int visit[31][31][31];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dz[2]={1,-1};
int main(void)
{
	int L,R,C;
	while(1)
	{
		
		scanf("%d %d %d",&L,&R,&C);
		if(L==0 && R==0 && C==0)
			break;
		int s_i,s_j,s_k;
		int e_i,e_j,e_k;
		memset(arr,0,sizeof(arr));
		memset(visit,-1,sizeof(visit));
		for(int i=0;i<L;i++)
		{
			for(int j=0;j<R;j++)
			{
				char st[31];
				scanf("%s",st);
				if(strlen(st)==0)
					continue;
				for(int k=0;k<C;k++)
				{
					arr[i][j][k]=st[k];	
					if(arr[i][j][k]=='S')
					{
						s_i=i;
						s_j=j;
						s_k=k;
					}
					if(arr[i][j][k]=='E')
					{
						e_i=i;
						e_j=j;
						e_k=k;
					}
				}
			}
		}
		
		queue<pair<int,pair<int,int> > > qq;
		qq.push(make_pair(s_i,make_pair(s_j,s_k)));
		visit[s_i][s_j][s_k]=0;
		while(!qq.empty())
		{
			pair<int,pair<int,int> > pp;
			pp=qq.front();
			qq.pop();
			int ii = pp.first;
			int jj = pp.second.first;
			int kk = pp.second.second;
			for(int i=0;i<4;i++)
			{
				int ddx = jj+dx[i];
				int ddy = kk+dy[i];
				if(ddx<0 || ddy<0 || ddx>=R || ddy>=C)
					continue;
				if(arr[ii][ddx][ddy]=='#')
					continue;
				if(visit[ii][ddx][ddy]==-1)
				{
					visit[ii][ddx][ddy]=visit[ii][jj][kk]+1;
					qq.push(make_pair(ii,make_pair(ddx,ddy)));
				}
			}
			for(int i=0;i<2;i++)
			{
				int ddx = ii + dz[i];
				if(ddx<0 || ddx>=L)
					continue;
				if(arr[ddx][jj][kk]=='#')
					continue;
				if(visit[ddx][jj][kk]==-1)
				{
					visit[ddx][jj][kk]=visit[ii][jj][kk]+1;
					qq.push(make_pair(ddx,make_pair(jj,kk)));
				}
			}		
		}	
		if(visit[e_i][e_j][e_k]==-1)
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",visit[e_i][e_j][e_k]);

		/*for(int i=0;i<L;i++)
		{
			for(int j=0;j<R;j++)
			{
				for(int k=0;k<C;k++)
				{
					printf("%c",arr[i][j][k]);
				}
				printf("\n");
			}
			printf("\n");
		}*/
	}
}
