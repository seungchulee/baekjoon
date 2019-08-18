#include <stdio.h>
int main(void)
{
	int N;
	scanf("%d",&N);

	int result=0;

	if(N<100)
		result=N;
	else{
		for(int i=100;i<=N;i++)
		{
			int one=i%10;
			int one_div=i/10;

			int two=one_div%10;
			int three=one_div/10;

			if(three-two == two-one)
				result++;
		}
		result+=99;
	}
	printf("%d",result);
}
