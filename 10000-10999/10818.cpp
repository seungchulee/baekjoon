#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> pq;
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		pq.push(x);
	}
	int y = pq.top();
	//printf("%d",pq.top());
	int x;
	while(!pq.empty())
	{
		x=pq.top();
		pq.pop();
	}
	printf("%d %d",x,y);
		
}
