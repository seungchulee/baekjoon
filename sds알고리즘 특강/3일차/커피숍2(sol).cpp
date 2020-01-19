#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int N,Q;
long long int arr[1<<20];
long long int getSum(int start, int end, int a, int b, int idx)
{
	long long int sum=0;
	if(start==a && end==b)
		return arr[idx];
	else
	{
		int ns = start;
		int ne = (start+end)/2;
		if(a>=ns && a<=ne)
			sum+=getSum(ns,ne,a,min(b,ne),idx*2);
		ns = (start+end)/2+1;
		ne = end;
		if(b>=ns && b<=ne)
			sum+=getSum(ns,ne,max(a,ns),b,idx*2+1);
		return sum;
	}
	
}
int main(void)
{
	scanf("%d %d",&N,&Q);
	memset(arr,0,sizeof(arr));
	int H = (int)log2(N-1)+1;
	int base = 1 << H;
	
	for(int i=base;i<base+N;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];

	for(int t=0;t<Q;t++)
	{
		int left,right;
		int a,b;
		scanf("%d %d %d %d",&left,&right,&a,&b);
		if(left>right)
		{
			long long int tmp = left;
			left=right;
			right=tmp;
		}
		long long int sum = getSum(1,base,left,right,1);
		//for(int i=1;i< base*2;i++)
		//	printf("%d ",arr[i]);
		printf("%lld\n",sum);
		arr[base+a-1]=b;
		long int start = base+a-1;
		while(start>1)
		{
			start/=2;
			arr[start]=arr[start*2]+arr[start*2+1];
		}
	}
}
