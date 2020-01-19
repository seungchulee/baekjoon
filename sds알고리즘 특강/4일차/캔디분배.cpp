#include <stdio.h>
#include <algorithm>
using namespace std;
long int gcd(long int a, long int b)
{
	long int maxs = max(a, b);
	long int mins = min(a, b);
	while (mins != 0)
	{
		long int re = maxs%mins;
		maxs = mins;
		mins = re;
	}
	return maxs;
}
int main(void)
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		long int K, C;
		scanf("%ld %ld", &K, &C);
		if (K == 1)
		{
			printf("1\n");
			continue;
		}
		if (C == 1)
		{
			if (K + 1 <= 1000000000)
			{
				printf("%ld\n", K + 1);
				continue;
			}
			else
			{
				printf("IMPOSSIBLE\n");
				continue;
			}
		}
		long int gcds = gcd(K, C);
		if (gcds != 1)
			printf("IMPOSSIBLE\n");
		else
		{
			long int arr[51][4];
			arr[0][0] = 1; arr[0][1] = 0; arr[0][2] = C;
			arr[1][0] = 0; arr[1][1] = 1; arr[1][2] = K;
			int start = 0;
			if (arr[0][2] > arr[1][2])
			{
				arr[2][0] = 1; arr[2][1] = 0; arr[2][2] = C;
				start = 3;
			}
			else
				start = 2;

			for (int i = start;; i++)
			{
				arr[i][2] = arr[i - 2][2] % arr[i - 1][2];
				arr[i][3] = arr[i - 2][2] / arr[i - 1][2];
				arr[i][0] = arr[i - 2][0] - arr[i][3] * arr[i - 1][0];
				arr[i][1] = arr[i - 2][1] - arr[i][3] * arr[i - 1][1];
				//intf("%d %d %d %d\n", arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
				if (arr[i][2] == 1)
				{
					//printf("%d %d\n", arr[i][0],arr[i][1]);
					if (arr[i][0] > 0)
					{
						if (arr[i][0] > 1000000000)
						{
							printf("IMPOSSIBLE\n");
							break;
						}
						printf("%ld\n", arr[i][0]);
					}
					else
					{
						int cc = 1;
						while (1)
						{
							if (cc*K + arr[i][0] > 0)
							{
								if (cc*K + arr[i][0] > 1000000000)
								{
									printf("IMPOSSIBLE\n");
									break;
								}
								printf("%ld\n", cc*K + arr[i][0]);
								break;
							}
							cc++;

						}
					}
					break;
				}
			}
			
		}

	}
}