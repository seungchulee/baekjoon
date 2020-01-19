#include <stdio.h>
#include <algorithm>
#include <algorithm>
#include <queue>
using namespace std;
pair<int,int> pp[300001];
int main(void)
{
	int N,K;
	scanf("%d %d",&N,&K);
	int wrr[300001];
	for(int i=0;i<N;i++)
		scanf("%d %d",&pp[i].first,&pp[i].second);
	for(int i=0;i<K;i++)
		scanf("%d",&wrr[i]);

	sort(wrr,wrr+K);
	sort(pp,pp+N);
	int idx=0;
	long int result=0;
	priority_queue<int> pq;
	for(int i=0;i<K;i++)
	{
		while(idx<N && pp[idx].first<=wrr[i])
		{
			pq.push(pp[idx].second);
			idx++;
		}

		if(!pq.empty())
		{
			result+=pq.top();
			pq.pop();
		}
	}
	
	printf("%ld",result);

}
