#include <stdio.h>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long int> arr;
vector<long long int> lazy;
int N;
int M;
int base;
void update_lazy(int start, int end, int idx)
{
	if(lazy[idx]==0)
		return;
	arr[idx]+=(end-start+1)*lazy[idx];
	if(start!=end)
	{
		lazy[idx*2]+=lazy[idx];
		lazy[idx*2+1]+=lazy[idx];
	}
	lazy[idx]=0;
}
void updates(int start, int end, int left, int right, int idx, int val)
{
	update_lazy(start,end,idx);

	if(left>end || right<start)
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
long long int finds(int start ,int end, int left ,int right, int idx)
{

	update_lazy(start,end,idx);
	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return arr[idx];
	return finds(start,(start+end)/2,left,right,idx*2)+finds((start+end)/2+1,end,left,right,idx*2+1);

}
int main(void)
{
	scanf("%d",&N);
	int h = (int)log2(N-1)+1;
	base = 1 << h;
	arr.resize(base*2+1);
	lazy.resize(base*2+1);
	for(int i=base;i<base+N;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int a,b;
			long long int c;
			scanf("%d %d %lld",&a,&b,&c);
			updates(1,base,a,b,1,c);
		}
		else
		{
			int a;
			scanf("%d",&a);
			long long int res = finds(1,base,a,a,1);
			printf("%lld\n",res);
		}
	}
}
