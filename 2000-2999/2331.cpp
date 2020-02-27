#include <stdio.h>
#include <cmath>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
int visit[303030];
int a,p;
int get(int x)
{
	int res=0;
	while(x>=1)
	{
		int y = x%10;
		res+=pow(y,p);
		x=x/10;
	}
	return res;
}
int main(void)
{
	cin >> a >> p;
	memset(visit,-1,sizeof(visit));
	vector<int> vv;
	int start;
	while(1)
	{
		if(visit[a]==1)
		{
			start = a;
			break;
		}
		vv.push_back(a);
		visit[a]=1;
		a = get(a);
		
		//cout << x << " ";
	}

	int cnt=0;
	for(int i=0;i<vv.size();i++)
	{
		if(vv[i]==start)
			break;
		cnt++;

	}
	cout << cnt;
}
