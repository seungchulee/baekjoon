#include <stdio.h>
#include <cstring>
int arr[1000];
int main(void)
{
	memset(arr,0,sizeof(arr));
	int N;
	scanf("%d",&N);

	int a=1;
	while(1)
	{
		if(a*(a+1)/2>1000)
			break;
		arr[a]=a*(a+1)/2;
		a++;
	}


	for(int i=0;i<N;i++)
	{
		int result;
		scanf("%d",&result);
	
		bool res=false;
		for(int i=1;i<a;i++)
		{
			for(int j=1;j<a;j++)
	
			{
				for(int k=1;k<a;k++)
				{
					if(arr[i]+arr[j]+arr[k]==result)
					{

						res=true;
					}
				}
			}
		}
		printf("%u\n",res);
	}

}
