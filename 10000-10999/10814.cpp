#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool sort1(const pair<int,pair<int,string> > &p1, const pair<int,pair<int,string> > &p2)
{
	if(p1.second.first == p2.second.first)
		return p1.first < p2.first;
	else
		return p1.second.first < p2.second.first;
}
int main(void)
{
	int n;
	cin >> n;
	vector<pair<int,pair<int,string> > > vv;
	for(int i=0;i<n;i++)
	{
		int x;
		string y;
		cin >> x >> y;
		vv.push_back(make_pair(i,make_pair(x,y)));
	}
	sort(vv.begin(),vv.end(),sort1);
	for(int i=0;i<n;i++)
	{
		cout << vv[i].second.first << ' ' << vv[i].second.second << '\n';
	}
}
