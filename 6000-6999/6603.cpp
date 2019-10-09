#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int n;
void func(int index,int one,int arr[],int check[])
{
	if(index==n)
	{
		if(one==6)
		{
			for(int i=0;i<n;i++)
			{
				if(check[i]==1)
					printf("%d ",arr[i]);
			}
			printf("\n");
		}
		return;
	}

	
	check[index]=1;
	func(index+1,one+1,arr,check);
	check[index]=0;
	func(index+1,one,arr,check);

}

int main(void)
{
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		int arr[14];
		int check[14];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		func(0,0,arr,check);
		printf("\n");
	}
}
