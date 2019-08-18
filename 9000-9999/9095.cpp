#include <stdio.h>
#include <algorithm>
using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);

	for(int i=0;i<T;i++)
	{
		int num;
		int arr[12];
		scanf("%d",&num);
		arr[1]=1;
		arr[2]=2;
		arr[3]=4;
		if(num>=4)
		{
			for(int j=4;j<=num;j++)
			{
				arr[j]=arr[j-1]+arr[j-2]+arr[j-3];
			}
		}
		printf("%d\n",arr[num]);
	}
}
