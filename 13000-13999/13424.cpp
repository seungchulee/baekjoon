#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int arr[101][101];
int fr[101];
bool sort1(const pair<int,int> &v1, const pair<int,int> &v2)
{
	if(v1.first==v2.first)
	{
		return v1.second<v2.second;
	}
	return v1.first < v2.first;
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)
					arr[i][j]=0;
				else
					arr[i][j]=10000000;
			}
		}	
		for(int i=0;i<m;i++)
		{
			int x,y,d;
			cin >> x >> y >> d;
			arr[x][y]=d;
			arr[y][x]=d;
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(arr[i][j] > arr[i][k]+arr[k][j])
						arr[i][j]=arr[i][k]+arr[k][j];
				}
			}
		}

		int k;
		cin >> k;
		for(int i=0;i<k;i++)
		{
			int idx;
			cin >> idx;
			fr[i]=idx;
		}
		int mins=10000000;
		vector<pair<int,int> > vv;
		for(int i=1;i<=n;i++)
		{
			int summ=0;
			for(int j=0;j<k;j++)
				summ+=arr[i][fr[j]];

			vv.push_back(make_pair(summ,i));
		}
		sort(vv.begin(),vv.end(),sort1);
		cout << vv[0].second << '\n';

	}
}
