#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<int> arr;
vector<int> lazy;
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
void update(int start ,int end, int left ,int right, int idx ,int val)
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
int find(int start, int end, int left, int right,int idx)
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
		scanf("%d",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]^arr[i*2+1];
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			a++;
			b++;
			update(1,base,a,b,1,c);
		}
		else
		{
			int a;
			scanf("%d",&a);
			a++;
			printf("%d\n",find(1,base,a,a,1));
		}
	}
}

