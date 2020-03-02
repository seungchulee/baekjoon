#include <stdio.h>
int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[55];
	arr[0]=0;
	arr[1]=1;
	arr[2]=1;
	for(int i=3;i<=54;i++)
		arr[i]=arr[i-1]+arr[i-2];
	printf("%d",arr[n]);
}
