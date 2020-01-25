#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
long int arr[4020202];
int N,Q;
long int find(int start, int end, int left, int right, int idx)
{
	if(start==left && right==end)
	{
		return arr[idx];
	}
	long int res = 0;
	int nstart=start;
	int nend=(start+end)/2;
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
	scanf("%d %d",&N,&Q);
	memset(arr,0,sizeof(arr));
	int H = (int)log2(N-1)+1;
	int base = 1 << H;
	for(int i=0;i<Q;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{
			int k = base + b - 1;
			arr[k]+=c;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
		}
		else
		{
			long int res = find(1, base, b, c, 1);
			printf("%ld\n",res);
		}
	}
}
