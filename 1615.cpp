#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
long int arr[8080];
long int find(int start, int end, int left, int right,int idx)
{
	if(left==start && right==end)
		return arr[idx];
	int nstart=start;
	int nend=(start+end)/2;
	long int res=0;
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
	memset(arr,0,sizeof(arr));
	int n,m;
	scanf("%d %d",&n,&m);
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	vector<pair<int,int> > vv;
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		vv.push_back(make_pair(x,y));
	}
	sort(vv.begin(),vv.end());
	long int cnt=0;
	for(int i=0;i<vv.size();i++)
	{
		int x=vv[i].first;
		int y=vv[i].second;
		cnt+= find(1,base,y+1,n,1);
		int k = base+y-1;
		arr[k]++;
		while(k>1)
		{
			k/=2;
			arr[k]=arr[k*2]+arr[k*2+1];
		}
	}
	printf("%ld",cnt);
}
