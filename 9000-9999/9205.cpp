#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)
	{
		int N;
		int arr[130][130];
		for(int i=0;i<110;i++)
		{
			for(int j=0;j<110;j++)
			{
				arr[i][j]=1000000000;
			}
		}
		for(int i=0;i<110;i++)
			arr[i][i]=0;
		vector<pair<int,int> > vv;
		scanf("%d",&N);
		int hx,hy;
		scanf("%d %d",&hx,&hy);
		vv.push_back(make_pair(hx,hy));
		for(int i=0;i<N;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			vv.push_back(make_pair(x,y));
		}
		int px,py;
		scanf("%d %d",&px,&py);
		vv.push_back(make_pair(px,py));
		for(int i=0;i<vv.size()-1;i++)
		{
			for(int j=i+1;j<vv.size();j++)
			{
				if(abs(vv[i].first-vv[j].first)+abs(vv[i].second-vv[j].second)<=1000)
				{
					arr[i][j]=1;
					arr[j][i]=1;
				}
			}
		}
		for(int k=0;k<vv.size();k++)
		{
			for(int i=0;i<vv.size();i++)
			{
				for(int j=0;j<vv.size();j++)
				{
					arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
				}
			}
		}
		if(arr[0][vv.size()-1]!=1000000000)
			printf("happy\n");
		else
			printf("sad\n");
	}


}
