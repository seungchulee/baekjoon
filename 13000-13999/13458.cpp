#include <stdio.h>
int main(void)
{
	int N;
	int arr[1000001];
	int B,C;

	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	scanf("%d %d",&B,&C);

	int result=0;
	result+=N;
	for(int i=0;i<N;i++)
	{
		arr[i]-=B;
		if(arr[i]<=0)
			continue;
		if(arr[i]<=C)
		{
			result+=1;
			continue;
		}
		else
		{
			if(arr[i]%C==0)
			{
				result+=arr[i]/C;
			}
			else
			{		
				result+=arr[i]/C+1;
			}
		}
	}
	printf("%d",result);
}
