#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int arr[100001];
void bin_search(int tmp)
{
	int start=0;
	int end=N-1;
	int mid;

	while(end>=start)
	{
		mid=(start+end)/2;
		if(arr[mid]==tmp)
		{
			printf("1\n");
			return;
		}
		else if(arr[mid]<tmp)
		{
			start=mid+1;
		}
		else
			end=mid-1;
	}
	printf("0\n");
	return;
}
int main(void)
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+N);
	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		bin_search(tmp);
	}
	
	return 0;
}
