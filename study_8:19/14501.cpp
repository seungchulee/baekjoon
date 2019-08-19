#include <stdio.h>
int N;
int T[15];
int P[15];
int result=0;
int max=-1;
void func(int index, int result)
{
	
	if(index>N)
	{
		return;
	}
	if(index==N)
	{
		if(max<result)
			max=result;
		return;
	}

	func(index+T[index],result+P[index]);
	func(index+1,result);
}
int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d %d",&T[i],&P[i]);
	func(0,result);
	printf("%d",max);

	return 0;
}
