#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
vector<vector<pair<int,int> > > vv;
int arr[1001][1001];
int main(void)
{
	int N,T;
	scanf("%d %d",&N,&T);
	vector<pair<int,pair<int,int> > > data;
	vv.resize(N+1);
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		data.push_back(make_pair(a,make_pair(b,c)));
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			if(i==j)
				arr[i][j]=0;
			else
				arr[i][j]=INT_MAX;
		}
	}

	for(int i=0;i<data.size();i++)
	{
		int ch = data[i].first;
		int x = data[i].second.first;
		int y = data[i].second.second;
		for(int j=0;j<data.size();j++)
		{
			if(i==j)
				continue;
			int chh = data[j].first;
			int xx = data[j].second.first;
			int yy = data[j].second.second;
			int dis = abs(x-xx)+abs(y-yy);

			if(ch==1 && chh==1)
			{
				if(dis>T)
					dis=T;
			}
			if(arr[i+1][j+1]==INT_MAX)
				arr[i+1][j+1]=dis;
			else
				arr[i+1][j+1]=min(arr[i+1][j+1],dis);

		}
	}
	for(int k=1;k<=N;k++)
	{
		for(int a=1;a<=N;a++)
		{
			for(int b=1;b<=N;b++)
			{
				if(a==b)
					continue;
				arr[a][b]=min(arr[a][b],arr[a][k]+arr[k][b]);
			}
		}
	}
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",arr[a][b]);
	}


}
