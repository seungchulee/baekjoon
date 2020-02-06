#include <stdio.h>
int main(void)
{
	int maxs=-1;
	int ii = 0;
	for(int i=1;i<=9;i++)
	{
		int x;
		scanf("%d",&x);
		if(maxs<x)
		{
			maxs=x;
			ii=i;
		}
	}
	printf("%d\n%d",maxs,ii);
}
