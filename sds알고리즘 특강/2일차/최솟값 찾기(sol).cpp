#include <stdio.h>
#include <deque>
#include <utility>
using namespace std;
int N, L;
long int arr[5000001];
deque<pair<int, int> > dd;
int main(void)
{
	scanf("%d %d", &N,&L);
	for (int i = 0; i < N; i++)
		scanf("%ld", &arr[i]);
	for (int i = 0; i < N; i++)
	{
		if (!dd.empty() && dd.front().second <= i - L)
			dd.pop_front();
		while (!dd.empty() && dd.back().first > arr[i])
			dd.pop_back();
		dd.push_back(make_pair(arr[i], i));
		printf("%d ", dd.front().first);
	}

}