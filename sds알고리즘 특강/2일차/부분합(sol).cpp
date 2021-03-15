#include <stdio.h>
#include <limits.h>
int N;
long int S;
long int arr[100001];
int main(void)
{
	scanf("%d %ld", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%ld", &arr[i]);
	}
	int i = 0;
	int j = 0;
	long int sum = 0;
	int mins = INT_MAX;
	while (1)
	{
		// printf("%d ", sum);
		int ii = i;
		int jj = j;

		if (sum >= S)
		{
			sum -= arr[i];
			int len = jj - ii;
			if (len < mins)
			{
				mins = len;
			}
			i++;

		}
		else if (j == N)
			break;
		else
		{
			sum += arr[j];
			j++;

		}

	}
	if (mins == INT_MAX)
		printf("0");
	else
		printf("%d", mins);
}