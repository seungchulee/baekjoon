#include <stdio.h>
#include <queue>
#include <map>
#include <functional>
using namespace std;
int K,N;
int arr[101];
map<long long int, bool> visited;
int main(void)
{
	scanf("%d %d",&K,&N);
	priority_queue<long long int,vector<long long int>, greater<long long int> > pq;
	for(int i=0;i<K;i++)
	{
		scanf("%d",&arr[i]);

	}
	int cnt=0;
	pq.push(1);
	long long int maxValue=0;
	while(N--)
	{
		long long int tmp = pq.top();
		pq.pop();
		for(int i=0;i<K;i++)
		{
			long long int tmp2 = tmp*arr[i];
			if(pq.size()>N && tmp2>maxValue)
				continue;
			if(!visited.count(tmp2))
			{
				maxValue=max(maxValue,tmp2);
				pq.push(tmp2);
				visited[tmp2]=true;
			}
		}
	}	
	printf("%lld",pq.top());
}

