#include <stdio.h>
#include <queue>
#include <functional>
using namespace std;
priority_queue< int, vector<int>, greater<int> > mins;
priority_queue< int > maxs;
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int x;
		scanf("%d", &x);
		if (maxs.size() > mins.size())
			mins.push(x);
		else
			maxs.push(x);

		if (!maxs.empty() && !mins.empty() && maxs.top() > mins.top())
		{
			int maxT = maxs.top();
			maxs.pop();
			int minT = mins.top();
			mins.pop();
			mins.push(maxT);
			maxs.push(minT);
		}
		printf("%d\n", maxs.top());
	}
}