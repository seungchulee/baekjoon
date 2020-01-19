#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
long int arr[1<<21];
long int brr[1<<21];
long int TT = 1000000001;
int N,M;
long int getmin(int start, int end, int left, int right, int idx)
{
	if(start==left && right==end)
		return brr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	long int res = TT;
	if(left>=nstart && left<=nend)
		res = min(res,getmin(nstart, nend, left,min(right,nend),idx*2));
	nstart = (start+end)/2+1;
	nend = end;
	if(right>=nstart && right<=nend)
		res = min(res,getmin(nstart, nend,max(left,nstart),right,idx*2+1));

	return res;
}
long int getmax(int start, int end, int left, int right, int idx)
{
	if(start==left && right==end)
		return arr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	long int res = -1;
	if(left>=nstart && left<=nend)
		res = max(res,getmax(nstart, nend, left,min(right,nend),idx*2));
	nstart = (start+end)/2+1;
	nend = end;
	if(right>=nstart && right<=nend)
		res = max(res,getmax(nstart, nend,max(left,nstart),right,idx*2+1));

	return res;
}
int main(void)
{
	memset(arr,-1,sizeof(arr));
	memset(brr,TT,sizeof(brr));
	scanf("%d %d",&N,&M);
	int H = (int)log2(N-1)+1;
	int base = 1 << H;

	for(int i=base;i<base+N;i++)
	{
		scanf("%ld",&arr[i]);
		brr[i]=arr[i];
	}
	for(int i=base-1;i>=1;i--)
	{
		arr[i]=max(arr[i*2],arr[i*2+1]);
		brr[i]=min(brr[i*2],brr[i*2+1]);
	}
	for(int t=0;t<M;t++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		long int mins = getmin(1,base,a,b,1);
		long int maxs = getmax(1,base,a,b,1);
		printf("%ld %ld\n",mins,maxs);
	}
}
