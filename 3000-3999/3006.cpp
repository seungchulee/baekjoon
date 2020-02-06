#include <stdio.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[404040];
int brr[404040];
vector<pair<int,int> > data;
int find(int start, int end, int left ,int right, int idx)
{
	if(left==start && right==end)
		return arr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	int res = 0;
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
	int n;
	scanf("%d",&n);
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		data.push_back(make_pair(x,i));
	}
	sort(data.begin(),data.end());
	for(int i=base;i<base+n;i++)
		arr[i]=1;
	for(int i=base-1;i>=1;i--)
		arr[i]=arr[i*2]+arr[i*2+1];
	for(int i=0;i<=n;i++)
		brr[i]=i+1;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			
			int cmp = brr[i/2];
			int idx = lower_bound(data.begin(),data.end(),make_pair(cmp,0))-data.begin();
			pair<int,int> pp = data[idx];
			idx = pp.second;
			int k = base + idx;
			arr[k]=0;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}

			int summ = find(1,base,1,idx+1,1);
			printf("%d\n",summ);
		}
		else
		{
			int cmp = brr[n-1-i/2];
			int idx = lower_bound(data.begin(),data.end(),make_pair(cmp,0))-data.begin();
			pair<int,int> pp = data[idx];
			idx = pp.second;
			int k = base+idx;
			arr[k]=0;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
			int summ = find(1,base,idx+1,n,1);
			printf("%d\n",summ);
		}

	}
}



