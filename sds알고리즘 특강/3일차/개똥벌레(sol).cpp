#include <stdio.h>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
int main(void)
{
	int N, H;
	scanf("%d %d", &N, &H);
	vector<int> first;
	vector<int> second;
	for (int i = 0; i < N/2; i++)
	{
		int x,y;
		scanf("%d %d", &x,&y);
		first.push_back(x);
		second.push_back(y);
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	
	int mins = INT_MAX;
	int minscnt = 1;
	for (int i = 1; i <= H; i++)
	{
		auto idx = first.size() - (lower_bound(first.begin(), first.end(), i)-first.begin());
		auto idx2 = second.size() - (lower_bound(second.begin(), second.end(), H - i+1)-second.begin());
		if (mins == idx + idx2)
			minscnt++;
		else if (mins > idx + idx2)
		{
			mins = idx + idx2;
			minscnt=1;
		}
	}
	printf("%d %d", mins, minscnt);
	return 0;
}