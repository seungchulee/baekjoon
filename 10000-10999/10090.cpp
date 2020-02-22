#include <stdio.h>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
long long int arr[4040404];
vector<pair<int,int> > vv;
long long int find(int start,int end, int left ,int right ,int idx)
{
	if(left>end || right<start)
		return 0;
	if(left<=start && end<=right)
		return arr[idx];
	return find(start,(start+end)/2,left,right,idx*2)+find((start+end)/2+1,end,left,right,idx*2+1);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(make_pair(x,i+1));
	}
	int h = (int)log2(n-1)+1;
	int base = 1 << h;
	sort(vv.begin(),vv.end());
	long long int cnt=0;
	for(int i=0;i<vv.size();i++)
	{
		int idx = vv[i].second;
		cnt+=find(1,base,idx,n,1);
		int k = base+idx-1;
		arr[k]++;
		while(k>1)
		{
			k/=2;
			arr[k]=arr[k*2]+arr[k*2+1];
		}
	}
	printf("%lld",cnt);
}
