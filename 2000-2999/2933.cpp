#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int R,C;
char basic[101][101];
int N;
int thrw[101];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int dir=0; // 0 : 왼쪽->오른쪽 , 1 : 오른쪽->왼쪽
int visit[101][101];
int mins=10000000;
vector<pair<int,int> > gravity(int x, int y)
{
	bool is_land=false;
	vector<pair<int,int> > ss;
	visit[x][y]=0;
	queue<pair<int,int> > qq;
	qq.push(make_pair(x,y));
	ss.push_back(make_pair(x,y));
	while(!qq.empty())
	{
		pair<int,int> pp=qq.front();
		qq.pop();
		int i=pp.first;
		int j=pp.second;
		for(int a=0;a<4;a++)
		{
			int ddx=i+dx[a];
			int ddy=j+dy[a];
			if(ddx<0 || ddy<0 || ddx>=R || ddy>=C)
				continue;
			if(basic[ddx][ddy]=='x' && visit[ddx][ddy]==-1)
			{
				
				visit[ddx][ddy]=0;
				if(ddx==R-1)
					is_land=true;
				qq.push(make_pair(ddx,ddy));
				
				ss.push_back(make_pair(ddx,ddy));
			}
		}
	}
/*	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			printf("%2d",visit[i][j]);
		}
		printf("\n");
	}*/
/*	printf("\n");

		for(int a=0;a<R;a++)
		{
			for(int b=0;b<C;b++)
			{
				printf("%c",basic[a][b]);
			}
			printf("\n");
		}
		printf("\n");
*/
	if(is_land==false)
	{
		int maxs=-1;
		int len=ss.size();

		int get_h[101];
		memset(get_h,-1,sizeof(get_h));
		for(int i=0;i<len;i++)
		{
			int xx=ss[i].first;
			int yy=ss[i].second;
			get_h[yy]=max(get_h[yy],xx);
		}
		for(int i=0;i<C;i++)
		{
			int cnt=0;
			if(get_h[i]!=-1)
			{
				for(int j=get_h[i]+1;j<R;j++)
				{
					if(basic[j][i]=='x')
						break;
					cnt++;
				}
				mins=min(cnt,mins);
			}
		}
/*		printf("!%d!",mins);
		for(int i=0;i<len;i++)
		{
			basic[ss[i].first][ss[i].second]='.';
		}
		for(int i=0;i<len;i++)
		{
			basic[ss[i].first+mins][ss[i].second]='x';
		}*/
	}
	return ss;
}
void BFS()
{
	memset(visit,-1,sizeof(visit));
	vector<pair<int,int> > ss;
	bool check;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(basic[i][j]=='x' && visit[i][j]==-1)
			{
				ss=gravity(i,j);
			}
		}
	}
	int len=ss.size();
	printf("%d",len);
	for(int i=0;i<len;i++)
	{
		printf("!%d %d!",ss[i].first,ss[i].second);
		basic[ss[i].first][ss[i].second]='.';
	}
	for(int i=0;i<len;i++)
	{
		basic[ss[i].first+mins][ss[i].second]='x';
	}

}

void throw_stick(int height)
{
	if(dir==0)
	{
		for(int i=0;i<C;i++)
		{
			if(basic[R-height][i]=='x')
			{
				basic[R-height][i]='.';
				break;
			}
		}
		dir=1;
	}
	else
	{
		for(int i=C-1;i>=0;i--)
		{
			if(basic[R-height][i]=='x')
			{
				basic[R-height][i]='.';
				break;
			}
		}	
		dir=0;
	}
}
int main(void)
{
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)
	{
		char st[101];
		scanf("%s",st);
		for(int j=0;j<C;j++)
		{
			basic[i][j]=st[j];
		}
	}
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&thrw[i]);
	}
	for(int i=0;i<N;i++)
	{
		// 1. 미네랄 맞을 때 까지 막대 던짐
		// 2. 클러스터 떠있으면 바닥으로 떨어
		throw_stick(thrw[i]);
		BFS();
	}
	for(int a=0;a<R;a++)
	{
		for(int b=0;b<C;b++)
		{
			printf("%c",basic[a][b]);
		}
		printf("\n");
	}
	
}
