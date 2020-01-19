#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long long int arr[1<<21];
int N,M,K;
long long int rest = 1000000007;
long long int getSum(int start, int end, int left, int right, int idx)
{
	if(start==left && end==right)
		return arr[idx];
	long long int ans = 1;
	int nstart = start;
	int nend = (start+end)/2;
	if(left>=nstart && left<=nend)
		ans*=(getSum(nstart,nend,left,min(right,nend),idx*2))%rest;
	
	nstart=(start+end)/2+1;
	nend = end;
	if(right>=nstart && right<=nend)
		ans*=(getSum(nstart,nend,max(left,nstart),right,idx*2+1))%rest;

	return ans;
}
int main(void)
{
	memset(arr,0,sizeof(arr));
	scanf("%d %d %d",&N,&M,&K);
	int H = (int)log2(N-1) +1 ;
	int base = 1 << H;
	for(int i=base;i<base+N;i++)
		scanf("%lld",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=(arr[i*2]*arr[i*2+1])%rest;

	for(int t=0;t<M+K;t++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{
			arr[base+b-1]=c;
			int k = base+b-1;
			while(k>1)
			{
				k/=2;
				arr[k]=(arr[k*2]*arr[k*2+1])%rest;
			}
		}
		else if(a==2)
		{

			long long int sum = getSum(1,base,b,c,1);
			printf("%lld\n",sum%rest);
		}
	}



}
