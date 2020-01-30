#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,M,K;
vector<long long int> arr;
vector<long long int> lazy;
void update_lazy(int idx, int start ,int end)
{
	if(lazy[idx]==0)
		return;
	arr[idx] += (end-start+1)*lazy[idx];
	if(start!=end)
	{
		lazy[idx*2]+=lazy[idx];
		lazy[idx*2+1]+=lazy[idx];
	}
	lazy[idx]=0;
}
void updates(int start ,int end, int left, int right, int idx, long long int val)
{
	update_lazy(idx,start,end);
	if(left > end || right<start)
		return;

	if(left<=start && end<=right)
	{
		arr[idx]+=(end-start+1)*val;	
		if(start!=end)
		{
			lazy[idx*2]+=val;
			lazy[idx*2+1]+=val;
		}
		return;
	}
	updates(start,(start+end)/2,left,right,idx*2,val);
	updates((start+end)/2+1,end,left,right,idx*2+1,val);

	arr[idx]=arr[idx*2]+arr[idx*2+1];
	
}
long long int finds(int start, int end, int left ,int right, int idx)
{
	update_lazy(idx,start,end);
	if(left>end || right<start)
		return 0;
	if(left <= start && end<=right)
		return arr[idx];
	return finds(start,(start+end)/2,left,right,idx*2)+finds((start+end)/2+1,end,left,right,idx*2+1);
}
int main(void)
{
	scanf("%d %d %d",&N,&M,&K);
	int h = (int)log2(N-1)+1;
	int base = 1 << h;
	arr.resize(2*base+1);
	lazy.resize(2*base+1);
	for(int i=base;i<base+N;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];

	for(int i=0;i<M+K;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int b,c;
			long long int d;
			scanf("%d %d %lld",&b,&c,&d);
			updates(1,base,b,c,1,d);
		}
		else
		{
			int b,c;
			scanf("%d %d",&b,&c);
			long long int res = finds(1,base,b,c,1);
			printf("%lld\n",res);
		}
	}
}
