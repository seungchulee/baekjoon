#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{
	
	int N;
	while(cin >> N)
	{
		vector<int> vv;
		vv.push_back(-1000000);
		int ans=0;
		for(int i=0;i<N;i++)
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
		printf("%d\n",ans);	
	}
}
