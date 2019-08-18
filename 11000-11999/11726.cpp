#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	int *res=(int*)malloc(sizeof(int)*(n+1));
	res[1]=1;
	res[2]=2;
	for(int i=3;i<=n;i++)
	{
		res[i]=res[i-1]+res[i-2];
		res[i]%=10007;
	}
	printf("%d",res[n]);
}

