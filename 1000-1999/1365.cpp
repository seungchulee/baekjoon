#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	scanf("%d",&n);
	int ans=0;
	vector<int> vv;
	vv.push_back(-1);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		if(vv[vv.size()-1]<x)
		{
			vv.push_back(x);
			ans++;
		}
		else
		{
			int y = lower_bound(vv.begin(),vv.end(),x)-vv.begin();
			vv[y]=x;
		}
	}
	printf("%d",n-ans);
}


