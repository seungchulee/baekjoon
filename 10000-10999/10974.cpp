#include <stdio.h>
int arr[10];
int c[10]={false};
int n;
void func(int index)
{
	if(index==n)
	{
		for(int j=0;j<n;j++)
			printf("%d ",arr[j]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(c[i]==true)
			continue;
		arr[index]=i;
		c[i]=true;
		func(index+1);
		c[i]=false;
	}
}
int main(void)
{
	scanf("%d",&n);
	func(0);
}
