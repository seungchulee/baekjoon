#include <stdio.h>
int arr[11];
int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	int cnt=0;
	for(int i=n-1;i>=0;i--)
	{
		if(k>=arr[i])
		{
			int re = (int)(k/arr[i]);
			cnt+=re;
			re = re * arr[i];
			k-=re;
		}
	}
	printf("%d",cnt);
}
