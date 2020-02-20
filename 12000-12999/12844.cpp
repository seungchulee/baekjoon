#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long int> arr;
vector<long long int> lazy;
void update_lazy(int idx, int start, int end)
{
	if(lazy[idx]==0)
		return;
	arr[idx]^=((end-start+1)%2)*lazy[idx];
	if(start!=end)
	{
		lazy[idx*2]^=lazy[idx];
		lazy[idx*2+1]^=lazy[idx];
	}
	lazy[idx]=0;
}
void update(int start, int end, int left, int right, int idx, long long int val)
{
	update_lazy(idx,start,end);
	if(left>end || right<start)
		return;
	if(left<=start && end<=right)
	{
		arr[idx]^=((end-start+1)%2)*val;
		if(start!=end)
		{
			lazy[idx*2]^=val;
			lazy[idx*2+1]^=val;
		}
		return;
	}
	update(start,(start+end)/2,left,right,idx*2,val);
	update((start+end)/2+1,end,left,right,idx*2+1,val);
	arr[idx]=arr[idx*2]^arr[idx*2+1];
}
long long int find(int start, int end, int left, int right,int idx)
{
	update_lazy(idx,start,end);
	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return arr[idx];	
	return find(start,(start+end)/2,left,right,idx*2)^find((start+end)/2+1,end,left,right,idx*2+1);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	arr.resize(base*2+1);
	lazy.resize(base*2+1);
	for(int i=base;i<base+n;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]^arr[i*2+1];
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==2)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(a>b)
				swap(a,b);
			a++;
			b++;
			long long int res = find(1,base,a,b,1);
			printf("%lld\n",res);
		}
		else
		{
			int a,b;
			long long int c;
			
			scanf("%d %d %lld",&a,&b,&c);
			if(a>b)
				swap(a,b);
			a++;
			b++;
			update(1,base,a,b,1,c);
		}

	}

}
