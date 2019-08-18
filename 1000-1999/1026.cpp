#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	scanf("%d",&N);

	int *A=(int*)malloc(sizeof(int)*N);
	int *B=(int*)malloc(sizeof(int)*N);
	for(int i=0;i<2*N;i++)
	{
		if(i<N)
			scanf("%d",&A[i]);
		else
			scanf("%d",&B[i-N]);

	}

	for(int i=0;i<N-1;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(A[i]>A[j])
			{
				int tmp=A[i];
				A[i]=A[j];
				A[j]=tmp;
			}
			if(B[i]<B[j])
			{
				int tmp2=B[i];
				B[i]=B[j];
				B[j]=tmp2;
			}	
		}
	}
	
	int result=0;
	for(int i=0;i<N;i++)
	{
		// printf("%d %d\n",A[i],B[i]);
		result+=A[i]*B[i];
	}
	printf("%d",result);
		
}
