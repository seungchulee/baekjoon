#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
vector<int> prime;
int check[4000001];
int main(void)
{
	memset(check, -1, sizeof(check));
	for (int i = 2; i <= 4000000; i++)
	{
		int cnt = 0;
		for (int j = i; j <= 4000000; j += i)
		{
			if (check[j] == -1 && cnt == 0)
			{
				cnt++;
				prime.push_back(i);
			}
			else if (check[j] == -1 && cnt == 1)
				check[j] = 1;
		}
	}
	int len = prime.size();
	int N;
	scanf("%d", &N);
	int i = 0, j = 0;
	int sum = 0;
	int result = 0;
	while (1)
	{
		if (sum > N)
		{
			sum -= prime[i];
			i++;
		}
		else if (j == len)
			break;
		else
		{
			sum += prime[j];
			j++;
		}

		if (sum == N)
			result++;
	}
	printf("%d", result);

}