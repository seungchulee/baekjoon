#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;
int N;
char arr[51][51];
int dist[51][51][2];
int x1;
int y1;
int e1,e2;
int dx[5]={0,0,-1,1,0 };
int dy[5]={1,-1,0,0,0 };
void BFS(int shape)
{
	queue<pair<pair<int,int>,pair<int,int> > > qq;
	//queue<pair<pair<int,int>,int> > qq;
	qq.push(make_pair(make_pair(x1,y1),make_pair(shape,0)));
	dist[x1][y1][shape]=0;
	while(!qq.empty())
	{	

		pair<pair<int,int>,pair<int,int> > ss;
		ss=qq.front();
		int xx=ss.first.first;
		int yy=ss.first.second;
		int sh=ss.second.first;
		int cnt=ss.second.second;
		qq.pop();

		if(sh==0) // ㅣ shape
		{

			/*if(yy-1<0 || yy+1>=N || xx-2<0 || xx+2>=N)
				continue;*/
			if(yy-1>=0 && dist[xx][yy-1][0]==-1 && arr[xx][yy-1]=='0' && arr[xx-1][yy-1]=='0' && arr[xx+1][yy-1]=='0')
			{
				qq.push(make_pair(make_pair(xx,yy-1),make_pair(0,0)));	
				dist[xx][yy-1][0]=dist[xx][yy][0]+1;
			} // left
			if(yy+1<N && dist[xx][yy+1][0]==-1 && arr[xx][yy+1]=='0' && arr[xx-1][yy+1]=='0' && arr[xx+1][yy+1]=='0')
			{
				qq.push(make_pair(make_pair(xx,yy+1),make_pair(0,0)));
				dist[xx][yy+1][0]=dist[xx][yy][0]+1;
			} // right
			
			if(xx-2>=0 && dist[xx-1][yy][0]==-1 && arr[xx-2][yy]=='0' )
			{
				qq.push(make_pair(make_pair(xx-1,yy),make_pair(0,0)));
				dist[xx-1][yy][0]=dist[xx][yy][0]+1;
			} // up
			if(xx+2<N && dist[xx+1][yy][0]==-1 && arr[xx+2][yy]=='0')
			{
				qq.push(make_pair(make_pair(xx+1,yy),make_pair(0,0)));
				dist[xx+1][yy][0]=dist[xx][yy][0]+1;
			} // down
			if(arr[xx-1][yy-1]=='0' && arr[xx-1][yy+1]=='0' && arr[xx+1][yy+1]=='0' && arr[xx+1][yy-1]=='0' && arr[xx][yy-1]=='0' && arr[xx][yy+1]=='0' && cnt==0)
			{
				qq.push(make_pair(make_pair(xx,yy),make_pair(1,1)));
				dist[xx][yy][1]=dist[xx][yy][0]+1;
			} // rotate
			
		}
		if(sh==1) // ㅡ shape
		{
			/*if(yy-2<0 || yy+2>=N || xx-1<0 || xx+1>=N)
				continue;*/

			if(xx-1>=0 && dist[xx-1][yy][1]==-1 && arr[xx-1][yy]=='0' && arr[xx-1][yy-1]=='0' && arr[xx-1][yy+1]=='0')
			{
				qq.push(make_pair(make_pair(xx-1,yy),make_pair(1,0)));
				dist[xx-1][yy][1]=dist[xx][yy][1]+1;
			} // up 
			if(xx+1<N && dist[xx+1][yy][1]==-1 && arr[xx+1][yy]=='0' && arr[xx+1][yy-1]=='0' && arr[xx+1][yy+1]=='0')
			{
				//printf("!");
				qq.push(make_pair(make_pair(xx+1,yy),make_pair(1,0)));
				dist[xx+1][yy][1]=dist[xx][yy][1]+1;
			} // down
			if(yy-2>=0 && dist[xx][yy-1][1]==-1 && arr[xx][yy-2]=='0')
			{
					
				qq.push(make_pair(make_pair(xx,yy-1),make_pair(1,0)));
				dist[xx][yy-1][1]=dist[xx][yy][1]+1;
			} // left
			if(yy+2<N && dist[xx][yy+1][1]==-1 && arr[xx][yy+2]=='0')
			{

				qq.push(make_pair(make_pair(xx,yy+1),make_pair(1,0)));
				dist[xx][yy+1][1]=dist[xx][yy][1]+1;
			} // right
			if(arr[xx-1][yy-1]=='0' && arr[xx-1][yy]=='0' && arr[xx-1][yy+1]=='0' && arr[xx+1][yy+1]=='0' && arr[xx+1][yy]=='0' && arr[xx+1][yy-1]=='0' && cnt==0)
			{

				qq.push(make_pair(make_pair(xx,yy),make_pair(0,1)));
				dist[xx][yy][0]=dist[xx][yy][1]+1;
			} // rotate
		}
	}
			
}
int main(void)
{
	memset(dist,-1,sizeof(dist));
	scanf("%d",&N);
	
	for(int i=0;i<N;i++)
	{
		char st[51];
		scanf("%s",st);
		for(int j=0;j<N;j++)
		{
			arr[i][j]=st[j];
		}
	}
	int cnt=0;
	int shape=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='B')
			{

				if(arr[i][j+1]=='B')
				{
					x1=i;
					y1=j+1;
					shape=1;
				}
				else if(arr[i+1][j]=='B')
				{
					x1=i+1;
					y1=j;
					shape=0;
				}
				cnt++;
				break;
			}	
		}
		if(cnt==1)
			break;
	}

	cnt=0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='E')
			{
				if(arr[i][j+1]=='E')
				{
					e1=i;
					e2=j+1;
				}
				else if(arr[i+1][j]=='E')
				{
					e1=i+1;
					e2=j;
				}
				cnt++;
				break;
			}
		}
		if(cnt==1)
			break;
	}
	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(arr[i][j]=='B' || arr[i][j]=='E')
				arr[i][j]='0';
		}
	}


	BFS(shape);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",dist[i][j][0]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d ",dist[i][j][1]);

		}
		printf("\n");
	}


	printf("\n%d %d",dist[e1][e2][0],dist[e1][e2][1]);
	
}
