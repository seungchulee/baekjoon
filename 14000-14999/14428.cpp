#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int arr[404040];
int N;
int origin[101010];
int find(int start, int end ,int left ,int right, int idx)
{
	if(start==left && right==end)
		return arr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	int lidx=0;
	if(left>=nstart && left<=nend)
	{
		lidx = find(nstart,nend,left,min(right,nend),idx*2);
	}
	int ridx=0;
	nstart = (start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
	{
		ridx = find(nstart,nend,max(left,nstart),right,idx*2+1);
	}


	if(origin[lidx]>origin[ridx])
		return ridx;
	else
		return lidx;
		
}
int main(void)
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&origin[i]);
	int H=(int)log2(N-1)+1;
	int base=1<<H;
	origin[0]=1000000100;
	memset(arr,0,sizeof(arr));
	for(int i=base;i<base+N;i++)
		arr[i]=i-base+1;
	for(int i=base-1;i>=1;i--)
	{
		if(origin[arr[i*2]] > origin[arr[i*2+1]])
			arr[i]=arr[i*2+1];
		else
			arr[i]=arr[i*2];
	}

	int M;
	scanf("%d",&M);
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{	
			origin[b]=c;
			int k = base+b-1;
			while(k>1)
			{
				k/=2;
				if(origin[arr[k*2]] > origin[arr[k*2+1]])
					arr[k]=arr[k*2+1];
				else
					arr[k]=arr[k*2];
			}

		}	
		else
		{
			int res = find(1,base,b,c,1);
			printf("%d\n",res);
		}
	}
}
