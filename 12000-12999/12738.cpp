#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(void)
{

	int N;
	cin >> N;
	vector<long int> vv;
	vv.push_back(-1000000001);
	int ans=0;
	for(int i=0;i<N;i++)
	{
		long int x;
		scanf("%ld",&x);
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
	printf("%d",ans);	
}


