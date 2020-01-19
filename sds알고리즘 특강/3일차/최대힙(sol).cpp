#include <stdio.h>
#include <functional>
#include <queue>
using namespace std;
priority_queue< int > pq;
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		long int x;
		scanf("%ld", &x);
		if (x == 0)
		{
			if (pq.empty())
			{
				printf("0\n");
				continue;
			}
			else
			{
				printf("%ld\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
}