#include <stdio.h>
#include <queue>
using namespace std;
int main(void)
{
	int N;
	scanf("%d",&N);
	priority_queue<int> pq;
	while(N>=1)
	{
		pq.push(N%10);
		N/=10;
	}
	while(!pq.empty())
	{
		printf("%d",pq.top());
		pq.pop();
	}
}
