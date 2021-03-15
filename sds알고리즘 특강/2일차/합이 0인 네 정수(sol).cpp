#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int arr[4001][4];
int n;
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
	}
	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(arr[i][0] + arr[j][1]);
		}
	}
	vector<int> v2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v2.push_back(arr[i][2] + arr[j][3]);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	long int result = 0;
	int len = v1.size();
	for (int i = 0; i < len; i++)
	{
		int target = v1[i];
		auto first = lower_bound(v2.begin(), v2.end(), -target);
		auto last = upper_bound(v2.begin(), v2.end(), -target);
		result += last - first;
	}
	printf("%ld", result);
}