#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int arr[404040];
int n;
int find(int start ,int end, int left ,int right, int idx)
{
	if(left==start && right==end)
		return arr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	int res=0;
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
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	for(int i=base;i<base+n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x%2==0)
			arr[i]=1;
		else
			arr[i]=0;
	}
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];

	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(a==1)
		{
			int k = base+b-1;
			if(c%2==0)
			{
				arr[k]=1;
			}
			else
				arr[k]=0;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}

		}
		else if(a==2)
		{
			int k = find(1,base,b,c,1);
			printf("%d\n",k);
		}
		else
		{
			int k = find(1,base,b,c,1);
			printf("%d\n",c-b+1-k);
		}
	}
}
