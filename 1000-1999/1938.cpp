#include <stdio.h>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
char arr[51][51];
int visit[51][51][2];
int N;
// 0 => garo
// 1 => sero
int main(void)
{
	scanf("%d",&N);
	memset(visit,-1,sizeof(visit));
	int b_i,b_j,b_cnt,b_dir;
	int e_i,e_j,e_cnt,e_dir;
	b_cnt=0;
	e_cnt=0;
	vector<pair<int,int> > vb;
	vector<pair<int,int> > ve;
	for(int i=0;i<N;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<N;j++)
		{
			arr[i][j]=st[j];
			if(arr[i][j]=='B')
			{
				arr[i][j]='0';
				vb.push_back(make_pair(i,j));
			}
			if(arr[i][j]=='E')
			{
				arr[i][j]='0';
				ve.push_back(make_pair(i,j));
			}
		}
	}

	b_i=vb[1].first;
	b_j=vb[1].second;
	if(vb[1].second>vb[0].second)
		b_dir=0;
	else
		b_dir=1;
	e_i=ve[1].first;
	e_j=ve[1].second;
	if(ve[1].second>ve[0].second)
		e_dir=0;
	else
		e_dir=1;
	visit[b_i][b_j][b_dir]=0;
	queue<pair<int,pair<int,int> > > qq;
	qq.push(make_pair(b_dir,make_pair(b_i,b_j)));
	while(!qq.empty())
	{
		pair<int,pair<int,int> > pp=qq.front();
		qq.pop();
		int dir = pp.first;
		int x = pp.second.first;
		int y = pp.second.second;

		if(dir==0)
		{
			//U
			if(x>0)
			{
				if(arr[x-1][y-1]=='0' && arr[x-1][y+1]=='0' && arr[x-1][y]=='0' && visit[x-1][y][dir]==-1)
				{
					visit[x-1][y][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x-1,y)));
				}
			}
			//D
			if(x+1<N)
			{
				if(arr[x+1][y]=='0' && arr[x+1][y-1]=='0' && arr[x+1][y+1]=='0' && visit[x+1][y][dir]==-1)
				{
					visit[x+1][y][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x+1,y)));
				}
			}
			//L
			if(y-1-1>=0)
			{
				if(arr[x][y-2]=='0' && visit[x][y-1][dir]==-1)
				{
					visit[x][y-1][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x,y-1)));
				}
			}
			//R
			if(y+1+1<N)
			{
				if(arr[x][y+2]=='0' && visit[x][y+1][dir]==-1)
				{
					visit[x][y+1][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x,y+1)));
				}
			}
			//T
			if(arr[x-1][y]=='0' && arr[x+1][y]=='0' && arr[x-1][y-1]=='0' && arr[x-1][y+1]=='0' && arr[x+1][y-1]=='0' && arr[x+1][y+1]=='0' && visit[x][y][1]==-1)
			{
				visit[x][y][1]=visit[x][y][dir]+1;
				qq.push(make_pair(1,make_pair(x,y)));
			}
		}
		else
		{
			//U
			if(x-1-1>=0)
			{
				if(arr[x-2][y]=='0' && visit[x-1][y][dir]==-1)
				{
					visit[x-1][y][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x-1,y)));
				}
			}
			//D
			if(x+1+1<N)
			{
				if(arr[x+2][y]=='0' && visit[x+1][y][dir]==-1)
				{
					visit[x+1][y][dir]=visit[x][y][dir]+1;
					qq.push(make_pair(dir,make_pair(x+1,y)));
				}
			}
			//L
			if(y-1>=0)
			{
				if(arr[x-1][y-1]=='0' && arr[x+1][y-1]=='0' && arr[x][y-1]=='0' && visit[x][y-1][dir]==-1)
				{
					qq.push(make_pair(dir,make_pair(x,y-1)));
					visit[x][y-1][dir]=visit[x][y][dir]+1;
				}
			}
			//R
			if(y+1<N)
			{
				if(arr[x-1][y+1]=='0' && arr[x+1][y+1]=='0' && arr[x][y+1]=='0' && visit[x][y+1][dir]==-1)
				{
					qq.push(make_pair(dir,make_pair(x,y+1)));
					visit[x][y+1][dir]=visit[x][y][dir]+1;
				}
			}
			//T
			if(arr[x][y-1]=='0' && arr[x][y+1]=='0'  && arr[x-1][y-1]=='0' && arr[x-1][y+1]=='0' && arr[x+1][y-1]=='0' && arr[x+1][y+1]=='0' && visit[x][y][0]==-1)
			{
				visit[x][y][0]=visit[x][y][dir]+1;
				qq.push(make_pair(0,make_pair(x,y)));
			}

		}
	}
	if(visit[e_i][e_j][e_dir]==-1)
		printf("0");
	else
		printf("%d",visit[e_i][e_j][e_dir]);
}
