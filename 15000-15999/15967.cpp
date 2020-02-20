#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long int> arr;
vector<long long int> lazy;
void update_lazy(int idx, int start ,int end)
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
void update(int start, int end, int left ,int right, int idx, int val)
{
	update_lazy(idx,start,end);
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
		return ;
	}
	update(start,(start+end)/2,left,right,idx*2,val);
	update((start+end)/2+1,end,left,right,idx*2+1,val);
	arr[idx]=arr[idx*2]+arr[idx*2+1];

}
long long int find(int start, int end, int left, int right, int idx)
{
	update_lazy(idx,start,end);
	if(start==left && right==end)
		return arr[idx];
	int nstart=start;
	int nend=(start+end)/2;
	long long int res =0;
	if(left>=nstart && left<=nend)
		res+=find(nstart,nend,left,min(right,nend),idx*2);
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		res+=find(nstart,nend,max(left,nstart),right,idx*2+1);
	return res;
}
int main(void)
{
	int n,x,y;
	scanf("%d %d %d",&n,&x,&y);
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	arr.resize(2*base+1);
	lazy.resize(2*base+1);

	for(int i=base;i<base+n;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
	{
		arr[i]=arr[i*2]+arr[i*2+1];
	}
	for(int i=0;i<x+y;i++)
	{
		int q;
		scanf("%d",&q);
		if(q==1)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			long long int res = find(1,base,a,b,1);
			printf("%lld\n",res);
		}
		else
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			update(1,base,a,b,1,c);
		}

	}
}

