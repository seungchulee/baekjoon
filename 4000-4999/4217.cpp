#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;
char arr[201][210];
int visit[1001][1010];
int decode[1000][1000];
int visit2[1000][1000];
int data[16][4];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int H,W;
set<int> ss;
bool check;
int first;
char ans[6]={'W','A','K','J','S','D'};
void DFS(int x, int y, int same, int cnt)
{
	visit[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		int ddx = x+dx[i];
		int ddy = y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=H || ddy>=4*W)
			continue;
		if(decode[ddx][ddy]==same && visit[ddx][ddy]==0)
			DFS(ddx,ddy,same,cnt);
	}
}
void DFS2(int x, int y, int same)
{
	visit2[x][y]=1;
	for(int i=0;i<4;i++)
	{
		int ddx = x+dx[i];
		int ddy=y+dy[i];
		if(ddx<0 || ddy<0 || ddx>=H || ddy>=4*W)
			continue;
		if(visit[ddx][ddy]==first)
		{
			check=true;
			continue;
		}
		if(visit[ddx][ddy]!=same)
			ss.insert(visit[ddx][ddy]);
		if(decode[ddx][ddy]==same && visit2[ddx][ddy]==0)
			DFS2(ddx,ddy,same);
	}
}
int main(void)
{
	for(int i=0;i<=15;i++)
	{
		int num = i;
		int idx=3;
		while(num!=0)
		{
			data[i][idx--]=num%2;
			num/=2;
		}
	}
	int start=1;

	while(1)
	{
		cin >> H >> W;
		if(H==0 && W==0)
			break;
		memset(arr,0,sizeof(arr));
		memset(visit,0,sizeof(visit));
		memset(decode,0,sizeof(decode));
		memset(visit2,0,sizeof(visit2));
		for(int i=0;i<H;i++)
		{
			char st[201];
			scanf("%s",st);
			for(int j=0;j<W;j++)
			{
				arr[i][j]=st[j];
			}
		}
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				int k;
				if(arr[i][j]>='0' && arr[i][j]<='9')
					k=arr[i][j]-'0';
				else if(arr[i][j]>='a' && arr[i][j]<='f')
					k=arr[i][j]-'a'+10;
				decode[i][j*4]=data[k][0];
				decode[i][j*4+1]=data[k][1];
				decode[i][j*4+2]=data[k][2];
				decode[i][j*4+3]=data[k][3];
			}
		}
		int cnt=2;
		first=-1;
		for(int i=0;i<H;i++)
		{	
			if(visit[i][0]==0 && decode[i][0]==0)
				DFS(i,0,decode[i][0],1);
			if(visit[i][4*W-1]==0 && decode[i][4*W-1]==0)
				DFS(i,4*W-1,decode[i][4*W-1],1);
		}
		for(int i=0;i<4*W;i++)
		{		
			if(visit[0][i]==0 && decode[0][i]==0)
				DFS(0,i,decode[0][i],1);
			if(visit[H-1][i]==0 && decode[H-1][i]==0)
				DFS(H-1,i,decode[H-1][i],1);
		}
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<4*W;j++)
			{

				if(visit[i][j]==0)
				{
					DFS(i,j,decode[i][j],cnt);
					cnt++;
				}
				if(decode[i][j]==0 && first==-1)
					first=visit[i][j];
			}
		}

		vector<char> vv;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<4*W;j++)
			{
				check=false;
				if(visit[i][j]==first)
					continue;
				if(visit2[i][j]==0)
				{
					DFS2(i,j,decode[i][j]);
					if(check==true)
						vv.push_back(ans[ss.size()-1]);
					ss.clear();
				}
			}
		}
		printf("Case %d: ",start);
		sort(vv.begin(),vv.end());
		for(int i=0;i<vv.size();i++)
			printf("%c",vv[i]);
		printf("\n");
		start++;
	}
}
