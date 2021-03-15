#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
int arr[4000001];
int find(int start, int end, int val, int idx)
{
	if(start==end)
		return start;
	else
	{
		if(val<=arr[idx*2])
			return find(start,(start+end)/2,val,idx*2);
		else
			return find((start+end)/2+1,end,val-arr[idx*2],idx*2+1);
	}
}
int main(void)
{
	int gaesu = 1111111;
	int N;
	scanf("%d",&N);
	memset(arr,0,sizeof(arr));
	int H = (int)log2(gaesu-1)+1;
	int base = 1 << H;

	for(int t=0;t<N;t++)
	{
		int A,B;
		scanf("%d %d",&A,&B);
		if(A==1)
		{
			int idx = find(1,base,B,1);
			printf("%d\n",idx);
			arr[base+idx-1]--;
			int k = base+idx-1;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
		}
		else if(A==2)
		{
			int C;
			scanf("%d",&C);
			arr[base+B-1]+=C;
			if(arr[base+B-1]<0)
				arr[base+B-1]=0;
			int k = base+B-1;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
		}
	}

}
