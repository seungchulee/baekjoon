#include <stdio.h>
int location(int arr[], int low, int high, int x)
{
	if(low>high)
		return 0;
	else
	{
		int mid=(int)((low+high)/2);
		if(x==arr[mid])
			return mid;
		else if(x>arr[mid])
		{
			return location(arr,mid+1,high,x);
		}
		else
		{
			return location(arr,low,mid-1,x);
		}
	}
}
int main(void)
{
	int arr[15]={1,3,5,6,8,10,11,14,16,19,20,25,27,30,43};
	
	int find;
	scanf("%d",&find);

	int result=location(arr,0,14,find);
	printf("index : %d\n",result);
}
