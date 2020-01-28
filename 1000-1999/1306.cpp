#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int arr[4040404];
int find(int start, int end, int left ,int right, int idx)
{
	if(start==left && end==right)
		return arr[idx];
	int nstart = start;
	int nend=(start+end)/2;
	int res = -1;
	if(left>=nstart && left<=nend)
		res=max(res,find(nstart,nend,left,min(right,nend),idx*2));

	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		res=max(res,find(nstart,nend,max(left,nstart),right,idx*2+1));

	return res;
}
int main(void)
{
	scanf("%d %d",&N,&M);
	memset(arr,-1,sizeof(arr));
	int H = (int)log2(N-1)+1;
	int base = 1 << H;
	for(int i=base;i<base+N;i++)
		scanf("%d",&arr[i]);
	for(int i=base-1;i>=1;i--)
		arr[i]=max(arr[i*2],arr[i*2+1]);
	int start = M;
	int end = N-M+1;
	for(int i=start;i<=end;i++)
		printf("%d ",find(1,base,i-(M-1),i+(M-1),1));
}
