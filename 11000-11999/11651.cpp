#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool sort1(const pair<int,int> &p1, const pair<int,int> &p2)
{
	if(p1.second==p2.second)
		return p1.first < p2.first;
	else
		return p1.second < p2.second;
}
int main(void)
{
	int n;
	cin >> n;
	vector<pair<int,int> > vv;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		vv.push_back(make_pair(x,y));
	}
	sort(vv.begin(),vv.end(),sort1);
	for(int i=0;i<vv.size();i++)
		printf("%d %d\n",vv[i].first,vv[i].second);
}
