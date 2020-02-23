#include <stdio.h>
int arr[1010];
int main(void)
{
	int c;
	scanf("%d",&c);
	for(int a=0;a<c;a++)
	{
		int N;
		scanf("%d",&N);
		float summ=0;
		for(int i=0;i<N;i++)
		{
			scanf("%d",&arr[i]);
			summ+=arr[i];
		}
		float avg = summ/N;
		float cnt=0;
		for(int i=0;i<N;i++)
		{
			if(arr[i]>avg)
				cnt++;
		}
		printf("%.3f%%\n",cnt/N*100);
	}
}
