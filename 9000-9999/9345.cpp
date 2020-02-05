#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int arr[404040];
int arr2[404040];
int vec[100010];
int N,M;
int find1(int start ,int end, int left ,int right, int idx)
{
	if(left>right)
		return -1;
	if(right<start || end<left)
		return -1;
	if(left<=start && end<=right)
		return arr[idx];
	int mid = (start+end)/2;
	return max(find1(start,mid,left,right,idx*2),find1(mid+1,end,left,right,idx*2+1));
}
int find2(int start ,int end, int left ,int right, int idx)
{
	if(left>right)
		return 10000000;
	if(right<start || end<left)
		return 10000000;
	if(left<=start && end<=right)
		return arr2[idx];
	int mid = (start+end)/2;
	return min(find2(start,mid,left,right,idx*2),find2(mid+1,end,left,right,idx*2+1));
}

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int q=0;q<t;q++)
	{
		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++)
			vec[i]=i+1;
		int h = (int)log2(N-1)+1;
		int base = 1 << h;
		for(int i=0;i<2*base+1;i++)
		{
			arr[i]=-1;
			arr2[i]=10000000;
		}
		for(int i=base;i<base+N;i++)
		{
			arr[i]=vec[i-base];
			arr2[i]=vec[i-base];
		}
		for(int i=base-1;i>=1;i--)
		{
			arr[i]=max(arr[i*2],arr[i*2+1]);
			arr2[i]=min(arr2[i*2],arr2[i*2+1]);
		}
		for(int i=0;i<M;i++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);

			if(a==0)
			{
				swap(arr[base+b],arr[base+c]);
				swap(arr2[base+b],arr2[base+c]);

				int k = base+b;
				while(k>1)
				{
					k/=2;
					arr[k]=max(arr[k*2],arr[k*2+1]);
					arr2[k]=min(arr2[k*2],arr2[k*2+1]);
				}
				k=base+c;
				while(k>1)
				{
					k/=2;
					arr[k]=max(arr[k*2],arr[k*2+1]);
					arr2[k]=min(arr2[k*2],arr2[k*2+1]);
				}

			}
			else
			{
				int maxs = find1(1,base,b+1,c+1,1)-1;
				int mins = find2(1,base,b+1,c+1,1)-1;

				if(mins==b && maxs==c)
					printf("YES\n");
				else
					printf("NO\n");
			}

		}
	}
}
