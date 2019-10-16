#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N;
int population[12];
int selectt[12];
vector<vector<int> > area;
int mins=10000000;
int possible()
{
	int visit[12];
	memset(visit,-1,sizeof(visit));
	int one;
	int zero;
	int one_cnt=0;
	int zero_cnt=0;
	for(int i=1;i<=N;i++)
	{
		if(selectt[i]==1)
		{
			one_cnt++;
			one=i;
		}
		else
		{
			zero_cnt++;
			zero=i;
		}
	}
	if(one_cnt==0 || zero_cnt==0)
		return -1;
	queue<int> ones;
	ones.push(one);
	int one_popul=0;
	int zero_popul=0;
	while(!ones.empty())
	{
		int start=ones.front();
		ones.pop();
		visit[start]=0;
		int len=area[start].size();
		for(int i=0;i<len;i++)
		{
			int end=area[start][i];
			if(visit[end]==-1 && selectt[end]==1)
			{
				ones.push(end);
			}
		}		
	}

	queue<int> zeros;
	zeros.push(zero);
	while(!zeros.empty())
	{
		int start=zeros.front();
		zeros.pop();
		visit[start]=0;
		int len=area[start].size();

		for(int i=0;i<len;i++)
		{
			int end=area[start][i];
			if(visit[end]==-1 && selectt[end]==0)
			{
				zeros.push(end);
			}
		}		

	}
	for(int i=1;i<=N;i++)
	{
		if(visit[i]==-1)
			return -1;
	}
	for(int i=1;i<=N;i++)
	{
		if(selectt[i]==1)
		{
			one_popul+=population[i];
		}
		else
		{
			zero_popul+=population[i];
		}
	}
/*	printf("%d %d\n",one_popul,zero_popul);	
	for(int i=1;i<=N;i++)
		printf("%d ",select[i]);
	printf("\n");
	for(int i=1;i<=N;i++)
		printf("%d ",visit[i]);
	printf("\n");*/
	return abs(one_popul-zero_popul);

}
void func(int index)
{
	if(index==N+1)
	{
		int result=possible();
		if(result==-1)
			return;
		else
			mins=min(mins,result);
		//printf("!");
		//for(int i=1;i<=N;i++)
		//	printf("%d ",select[i]);
		//printf("\n");

		return;
	}

	selectt[index]=1;
	func(index+1);
	selectt[index]=0;
	func(index+1);
}
int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&population[i]);

	area.resize(N+1);
	for(int i=1;i<=N;i++)
	{
		int a,b;
		scanf("%d",&a);
		for(int j=0;j<a;j++)
		{
			scanf("%d",&b);
			area[i].push_back(b);
		}


	}
	memset(selectt,-1,sizeof(selectt));

	for(int i=1;i<=N-1;i++)
	{
		func(i);
	}
	if(mins==-1 || mins==10000000)
		printf("-1");
	else
		printf("%d",mins);

}
