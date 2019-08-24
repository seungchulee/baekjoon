#include <stdio.h>
int N;
int main(void)
{
	scanf("%d",&N);
	
	int cnt=0;

	for(int i=1;i<=N;i++)
	{
		if(i%5==0)
			cnt++;
		if(i%25==0)
			cnt++;
		if(i%125==0)
			cnt++;
	}
	printf("%d",cnt);
}
