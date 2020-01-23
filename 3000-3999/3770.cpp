#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N,M,K;
vector<vector<int> > vv;
int arr[4040];
long int find(int start, int end, int left, int right, int idx)
{
	if(left==start && right==end)
		return arr[idx];
	int nstart = start;
	int nend = (start+end)/2;
	long int res = 0;
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
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		vv.clear();
		long int ans=0;
		memset(arr,0,sizeof(arr));
		scanf("%d %d %d",&N,&M,&K);
		vv.resize(N+1);
		int H = (int)log2(M-1)+1;
		int base = 1 << H;
		
		for(int i=0;i<K;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			vv[a].push_back(b);

		}
		for(int i=1;i<=N;i++)
			sort(vv[i].begin(),vv[i].end());

		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<vv[i].size();j++)
			{

				long int summ = find(1,base,vv[i][j]+1,M,1);
				int k = base + vv[i][j] - 1;
				arr[k]++;
				while(k>1)
				{
					k/=2;
					arr[k]=arr[k*2]+arr[k*2+1];
				}
				ans+=summ;
		
			}

		}
		printf("Test case %d: %ld\n",t,ans);
	}
}

