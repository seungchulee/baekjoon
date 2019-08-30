#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;
int N,M;
int arr[51][51];
int minsmins=10000000;
vector<pair<int,int> > one;
vector<pair<int,int> > two;
int check[14];
void func(int index,int cnt)
{
	if(index>two.size())
		return;
	if(cnt==M)
	{
		
		int sum=0;
		for(int i=0;i<one.size();i++)
		{
			pair<int,int> ss;
			ss=one[i];
			int xx=ss.first;
			int yy=ss.second;

			int mins=10000000;
			for(int j=0;j<two.size();j++)
			{
				if(check[j]==1)
				{
					pair<int,int> dd;
					dd=two[j];
					int xxx=dd.first;
					int yyy=dd.second;

					int dist=abs(xx-xxx)+abs(yy-yyy);
					mins=min(dist,mins);
				}

			}
			sum+=mins;
		}
		minsmins=min(sum,minsmins);

		return;
	}
	
	check[index]=1;
	func(index+1,cnt+1);

	check[index]=0;
	func(index+1,cnt);

}
int main(void)
{
	scanf("%d %d",&N,&M);
	memset(check,0,sizeof(check));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1)
				one.push_back(make_pair(i,j));
			if(arr[i][j]==2)
			{
				two.push_back(make_pair(i,j));
			}
		}
	}

	func(0,0);

	printf("%d",minsmins);	
}
