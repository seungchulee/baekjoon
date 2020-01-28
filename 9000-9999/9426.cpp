#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
int arr[250010];
long long int tree[303030];
int N,K;
long long int find(int start ,int end, int gaesu, int idx)
{
	if(start==end)
		return start;
	if(tree[idx*2] >= gaesu)
		return find(start,(start+end)/2,gaesu,idx*2);
	else
		return find((start+end)/2+1,end,gaesu-tree[idx*2],idx*2+1);
}
int main(void)
{
	scanf("%d %d",&N,&K);
	memset(tree,0,sizeof(tree));
	int H = (int)log2(N-1)+1;
	int base = 1 << H;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&arr[i]);
		arr[i]+=1;
	}

	for(int i=0;i<K-1;i++)
	{		
		int k = base+arr[i]-1;
		tree[k]++;
		while(k>1)
		{
			k/=2;
			tree[k]=tree[k*2]+tree[k*2+1];
		}
	}
	long long int res=0;
	for(int i=K-1;i<N;i++)
	{
		int k = base+arr[i]-1;
		tree[k]++;
		while(k>1)
		{
			k/=2;
			tree[k]=tree[k*2]+tree[k*2+1];
		}
		//for(int i=1;i<base*2;i++)
		//	printf("%lld ",tree[i]);
		//printf("\n");
		res+=(find(1,base,(K+1)/2,1)-1);
		//printf("!%lld!",res);
		k = base+arr[i-K+1]-1;
		tree[k]--;
		while(k>1)
		{
			k/=2;
			tree[k]=tree[k*2]+tree[k*2+1];
		}
		//for(int i=1;i<base*2;i++)
		//	printf("%lld ",tree[i]);
		//printf("\n\n");
	

	}
	printf("%lld",res);
}

