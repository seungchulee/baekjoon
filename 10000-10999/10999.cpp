#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long int arr[2020202];
long long int lazy[2020202];
int base;
void update_lazy(int idx, int start ,int end)
{
	if(lazy[idx]!=0)
	{
		arr[idx]+=(end-start+1)*lazy[idx];
		if(start!=end)
		{
			lazy[idx*2]+=lazy[idx];
			lazy[idx*2+1]+=lazy[idx];
		}
		lazy[idx]=0;
	}
}

long long int find(int start, int end, int left, int right, int idx)
{
	update_lazy(idx,start,end);
	if(left>end || right<start)
		returnr 0;
	if(start==left && end==right)
		return arr[idx];
	int summ=0;
	int nstart = start;
	int nend = (start+end)/2;
	if(left>=nstart && left<=nend)
		summ+=find(nstart,nend,left,min(right,nend),idx*2);
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		summ+=find(nstart,nend,max(left,nstart),right,idx*2+1);

	return summ;

}
void updates(int start, int end, int left, int right, int idx,long long int val)
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
		return;
	}
	updates(start,(start+end)/2,left,right,idx*2,val);
	updates((start+end)/2+1,end,left,right,idx*2+1,val);
	arr[idx]=arr[idx*2]+arr[idx*2+1];
	

}
int main(void)
{
	int N,M,K;
	scanf("%d %d %d",&N,&M,&K);
	int H = (int)log2(N-1)+1;
	base = 1<< H;
	memset(arr,0,sizeof(arr));
	memset(lazy,0,sizeof(lazy));
	for(int i=base;i<base+N;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];
	for(int i=0;i<M+K;i++)
	{
		int id;
		scanf("%d",&id);
		if(id==1)
		{
			int a,b;
			long long int c;
			scanf("%d %d %lld",&a,&b,&c);
			updates(1,base,a,b,1,c);
		}
		else
		{
			int a,b;
			scanf("%d %d",&a,&b);
			printf("%lld\n",find(1,base,a,b,1));
		}
	}
}
