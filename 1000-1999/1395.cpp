#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,M;
vector<int> arr;
vector<int> lazy;
void update_lazy(int idx, int start ,int end)
{
	if(lazy[idx]==0)
		return;
	arr[idx]=(end-start+1)-arr[idx];
	if(start!=end)
	{
		lazy[idx*2]=!lazy[idx*2];
		lazy[idx*2+1]=!lazy[idx*2+1];
	}
	lazy[idx]=0;
}
int updates(int start ,int end, int left ,int right,int idx, int val)
{
	update_lazy(idx,start,end);
	if(left>end || right<start)
		return arr[idx];
	if(left<=start && end<=right)
	{
		arr[idx]=(end-start+1)-arr[idx];
		if(start!=end)
		{
			lazy[idx*2]=!lazy[idx*2];
			lazy[idx*2+1]=!lazy[idx*2+1];
		}
		return arr[idx];
	}
	return arr[idx]=updates(start,(start+end)/2,left,right,idx*2,val)+updates((start+end)/2+1,end,left,right,idx*2+1,val);


}
int finds(int start ,int end, int left, int right, int idx)
{
	update_lazy(idx,start,end);
	if(start==left && right==end)
	{
		return arr[idx];
	}
	int nstart=start;
	int nend=(start+end)/2;
	int res=0;
	if(left>=nstart && left<=nend)
	{
		res+=finds(nstart,nend,left,min(right,nend),idx*2);


	}
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
	{
		res+=finds(nstart,nend,max(left,nstart),right,idx*2+1);

	}
	return res;
}
int main(void)
{
	scanf("%d %d",&N,&M);
	int h = (int)log2(N-1)+1;
	int base = 1 << h;
	arr.resize(base*2+1);
	lazy.resize(base*2+1);
	for(int i=0;i<base*2+1;i++)
	{
		arr[i]=0;
		lazy[i]=0;
	}
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==0)
		{
			updates(1,base,b,c,1,1);
		}
		else
		{
			int res = finds(1,base,b,c,1);
			printf("%d\n",res);
		}


	}

}
