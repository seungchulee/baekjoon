#include <stdio.h>
int gaesu[51];
int main(void)
{
	int M, K;
	scanf("%d", &M);
	int who = 0;
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &gaesu[i]);
		who += gaesu[i];
	}
	scanf("%d", &K);

	if (M == 1 || K==1)
		printf("1.0");
	else
	{
		double whonum = 0.0;
		for (int i = 0; i < M; i++)
		{
			int k = K;
			int ja = gaesu[i];
			int mo = who;
			if (gaesu[i] < K)
				continue;
			double num = (double)ja / (double)mo;
			while (k>1)
			{
				ja -= 1;
				mo -= 1;
				k--;
				num *= (double)ja / (double)mo;
			}
			// printf("!%.15lf\n", num);
			whonum += num;
		}
		printf("%.15lf", whonum);
	}
}