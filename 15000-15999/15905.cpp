#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > vv;
bool sort1(const pair<int,int> &p1, const pair<int,int> &p2)
{
	if(p1.first>p2.first)
		return true;
	else
	{
		if(p1.first==p2.first)
			return p1.second<p2.second;
		else
			return false;
	}
}
int main(void)
{
	int n; 
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin >> x >> y;
		vv.push_back(make_pair(x,y));
	}
	sort(vv.begin(),vv.end(), sort1);
	int sc = vv[4].first;
	int pe = vv[4].second;
	int cnt=0;
	for(int i=4;i<vv.size();i++)
	{
		if(vv[i].first==sc)
			if(vv[i].second>pe)
				cnt++;
	}
	printf("%d",cnt);
}
