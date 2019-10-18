#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int N,M;
char pan[11][11];
int visit[11][11][11][11];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int holex,holey;
int redx,redy,bluex,bluey;
queue<pair<pair<int,int>,int > > red;
queue<pair<int,int> > blue;
int main(void)
{
	memset(visit,-1,sizeof(visit));
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		char st[11];
		scanf("%s",st);
		for(int j=0;j<M;j++)
		{
			pan[i][j]=st[j];
			if(pan[i][j]=='R')
			{
				redx=i;
				redy=j;
				red.push(make_pair(make_pair(i,j),0));
			}
			if(pan[i][j]=='B')
			{
				bluex=i;
				bluey=j;
				blue.push(make_pair(i,j));
			}
			if(pan[i][j]=='O')
			{
				holex=i;
				holey=j;
			}
		}
	}
	//printf("!!%d %d!!\n",holex,holey);
	visit[redx][redy][bluex][bluey]=0;
	int result=0;
	while(!red.empty())
	{
		int rx=red.front().first.first;
		int ry=red.front().first.second;
		int cound=red.front().second;
		red.pop();
		int bx=blue.front().first;
		int by=blue.front().second;
		blue.pop();

		if(cound>=10)
			break;
		for(int i=0;i<4;i++)
		{
			int drx=rx;
			int dry=ry;
			int dbx=bx;
			int dby=by;
			int red_dis=0;
			int blue_dis=0;
		//	printf("==%d %d %d %d==\n",drx,dry,dbx,dby);
			while(1)
			{
				if(pan[drx+dx[i]][dry+dy[i]]=='O')
				{
					drx+=dx[i];
					dry+=dy[i];
					red_dis++;
					break;
				}

				if(pan[drx+dx[i]][dry+dy[i]]=='#')
				{
					break;
				}
				
				drx+=dx[i];
				dry+=dy[i];
				red_dis++;
			}
			while(1)
			{
				if(pan[dbx+dx[i]][dby+dy[i]]=='O')
				{
					dbx+=dx[i];
					dby+=dy[i];
					blue_dis++;
					break;
				}

				if(pan[dbx+dx[i]][dby+dy[i]]=='#')
				{
					break;
				}
				
				dbx+=dx[i];
				dby+=dy[i];
				blue_dis++;
			}
			//printf("==%d %d %d %d==\n",drx,dry,dbx,dby);

			/*while(pan[drx+dx[i]][dry+dy[i]] != '#' || pan[drx][dry]!='O')
			{
				drx+=dx[i];
				dry+=dy[i];
				red_dis++;
			}
			while(pan[dbx+dx[i]][dby+dy[i]] != '#' || pan[dbx][dby]!='O')
			{
				dbx+=dx[i];
				dby+=dy[i];
				blue_dis++;
			}*/

			if(dbx==holex && dby==holey)
				continue;
			if(drx==holex && dry==holey)
			{
				printf("1");
				return 0;
			}
			if(dbx==drx && dby==dry)
			{
				if(red_dis>blue_dis)
				{
					drx-=dx[i];
					dry-=dy[i];
				}
				else
				{
					dbx-=dx[i];
					dby-=dy[i];
				}
			}
		//	printf("==%d %d %d %d==\n",drx,dry,dbx,dby);

			if(visit[drx][dry][dbx][dby]==0)
				continue;
			visit[drx][dry][dbx][dby]=0;
			red.push(make_pair(make_pair(drx,dry),cound+1));
			blue.push(make_pair(dbx,dby));
		}
		
	}
	printf("0");

	return 0;

}
