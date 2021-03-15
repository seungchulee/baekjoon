#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int arr[5000000];
int find(int start, int end, int k, int idx)
{
	if(start==end)
		return start;
	else
	{
		if(k<=arr[idx*2])
			return find(start,(start+end)/2,k,idx*2);
		else
			return find((start+end)/2+1,end,k-arr[idx*2],idx*2+1);
	}
}	

int main(void)
{
	memset(arr,0,sizeof(arr));

	int gaesu = 2000020;
	int H = (int)log2(gaesu-1)+1;
	int base = 1 << H;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==1)
		{
			arr[b+base-1]++;
			int k = b+base-1;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
		}	
		else
		{
			int data = find(1,base,b,1);

			arr[base+data-1]--;
			int k = base+data-1;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
			printf("%d\n",data);
		}
	}
}
