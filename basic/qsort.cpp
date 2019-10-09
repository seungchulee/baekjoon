#include <stdio.h>
#define SWAP(a,b) { int tmp=a;a=b;b=tmp;}
int partition(int arr[], int left, int right)
{
	int i,pivot;
	pivot=left;

	for(i=left;i<right;i++)
	{
		if(arr[i]<arr[right])
		{
			SWAP(arr[i],arr[pivot]);
			pivot++;
		}
	}
	SWAP(arr[right],arr[pivot]);
	return pivot;
}

void quick_sort(int arr[],int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot=partition(arr,left,right);
		quick_sort(arr,left,pivot-1);
		quick_sort(arr,pivot+1,right);

	}
}
int main(void)
{
	int arr[15]={1,18,35,28,59,20,12,36,6,50,63,79,31,65,48};
	quick_sort(arr,0,14);

	for(int i=0;i<15;i++)
		printf("%d ",arr[i]);

}
