#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
long long int arr[2020200];
bool sort1(const pair<int,pair<int,int> > &p1,const pair<int,pair<int,int> > &p2)
{
	return p1.second.first < p2.second.first;
}
long long int finds(int start ,int end, int left ,int right, int idx)
{
	if(left==start && right==end)
	{
		return arr[idx];
	}

	int nstart = start;
	int nend = (start+end)/2;
	long long int res = 0;
	if(left>=nstart && left<=nend)
		res+=finds(nstart,nend,left,min(right,nend),idx*2);
	nstart=(start+end)/2+1;
	nend=end;
	if(right>=nstart && right<=nend)
		res+=finds(nstart,nend,max(left,nstart),right,idx*2+1);
	return res;
}
int main(void)
{
	int N;
	scanf("%d",&N);
	int h = (int)log2(N-1)+1;
	int base = 1 << h;
	memset(arr,0,sizeof(arr));
	long long int res=0;
	vector<pair<int,pair<int,int> > > vv;
	for(int i=1;i<=N;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(make_pair(x,make_pair(i,0)));
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<vv.size();i++)
		vv[i].second.second=i+1;

	sort(vv.begin(),vv.end(),sort1);
	for(int i=0;i<vv.size();i++)
	{
		int k = base+vv[i].second.second-1;

		res+=finds(1,base,vv[i].second.second,N,1);
		arr[k]++;
		while(k>1)
		{
			k/=2;
			arr[k]=arr[k*2]+arr[k*2+1];
		}
	}
	printf("%lld",res);
}
