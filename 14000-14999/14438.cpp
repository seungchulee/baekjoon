#include <stdio.h>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;
int arr[404040];
int N,M;
int find(int start, int end, int left, int right, int idx)
{
	if(start==left && end==right)
		return arr[idx];
	int nstart = start; 
	int nend = (start+end)/2;
	int mims = INT_MAX;
	if(left>=nstart && left<=nend)
		mims=min(mims,find(nstart,nend,left,min(right,nend),idx*2));
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		mims=min(mims,find(nstart,nend,max(left,nstart),right,idx*2+1));

	return mims;
}
int main(void)
{
	scanf("%d",&N);
	int H = (int)log2(N-1)+1;
	int base = 1 << H;
	for(int i=1;i<base*2;i++)
		arr[i]=INT_MAX;
	for(int i=base;i<base+N;i++)
		scanf("%d",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=min(arr[i*2],arr[i*2+1]);

	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{
			int k = base + b - 1;
			arr[k]=c;
			while(k>1)
			{
				k/=2;
				arr[k]=min(arr[k*2],arr[k*2+1]);
			}
		}
		else
		{
			int res = find(1,base,b,c,1);
			printf("%d\n",res);
		}
	
	}

}
