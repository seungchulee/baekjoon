#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<long long int> vv;
	for(int i=0;i<n+m;i++)
	{
		long long int x;
		scanf("%lld",&x);
		vv.push_back(x);
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<vv.size();i++)
		printf("%lld ",vv[i]);
}
