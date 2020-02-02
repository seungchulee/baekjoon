#include <stdio.h>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
bool sort1(const pair<int,pair<int,int> > &p1,const pair<int,pair<int,int> > &p2)
{	
	return p1.second.first < p2.second.first;
}
int arr[404040];
long int find(int start,int end ,int left, int right, int idx)
{
	if(left==start && right==end)
		return arr[idx];
	long int res=0;

	int nstart=start;
	int nend=(start+end)/2;
	if(left>=nstart && left<=nend)
	{
		res+=find(nstart,nend,left,min(right,nend),idx*2);
	}
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		res+=find(nstart,nend,max(left,nstart),right,idx*2+1);



	return res;
}

int main(void)
{
	int t;
	scanf("%d",&t);
	for(int a=0;a<t;a++)
	{
		int N;
		scanf("%d",&N);
		vector<pair<int,pair<int,int> > > vv;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d",&x);
			vv.push_back(make_pair(x,make_pair(i+1,0)));
		}

		vector<pair<int,pair<int,int> > > vs;
		for(int i=0;i<N;i++)
		{
			int x;
			scanf("%d",&x);
			vs.push_back(make_pair(x,make_pair(i+1,0)));
		}
		sort(vv.begin(),vv.end());
		sort(vs.begin(),vs.end());
		for(int i=0;i<vv.size();i++)
		{
			vv[i].second.second=vs[i].second.first;
		}	
		sort(vv.begin(),vv.end(),sort1);
		memset(arr,0,sizeof(arr));
		long int res=0;
		int h = (int)log2(N-1)+1;
		int base = 1 << h;
		for(int i=0;i<vv.size();i++)
		{
			int k = base+vv[i].second.second-1;
			res+=find(1,base,vv[i].second.second,N,1);

			arr[k]++;
			while(k>1)
			{
				k/=2;
				arr[k]=arr[k*2]+arr[k*2+1];
			}
		}
		printf("%ld\n",res);
	}
}
