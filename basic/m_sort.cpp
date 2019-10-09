#include <stdio.h>
int sorted[15];
void merge(int list[],int left, int mid, int right)
{
	int i,j,k,l;
	i=left;
	j=mid+1;
	k=left;

	while(i<=mid && j<=right)
	{
		if(list[i]<=list[j])
			sorted[k++]=list[i++];
		else
			sorted[k++]=list[j++];
	}
	
	if(i>mid)
	{
		for(l=j;l<=right;l++)
			sorted[k++]=list[l];
	}
	else
	{
		for(l=i;l<=mid;l++)
			sorted[k++]=list[l];
	}

	for(l=left;l<=right;l++)
		list[l]=sorted[l];


}
void merge_sort(int arr[], int left, int right)
{
	int middle;
	if(left<right)
	{
		middle=(left+right)/2;
		merge_sort(arr,left,middle);
		merge_sort(arr,middle+1,right);

		merge(arr,left,middle,right);
	}
}
int main(void)
{
	int arr[15]={1,39,2,44,13,53,20,55,34,10,6,31,54,36,64};
	merge_sort(arr,0,14);
	
	for(int i=0;i<15;i++)
		printf("%d ",arr[i]);
}
