#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	
	stack<pair<int,int> > ss;
	int res=0;
	while(n--)
	{
		int x;
		cin >> x;
		if(x==1)
		{
			int j,t;
			cin >> j >> t;
			ss.push(make_pair(j,t));
		}
		if(ss.empty())
			continue;
		pair<int,int> s= ss.top();
		ss.pop();
		if(s.second==1)
			res+=s.first;
		else
			ss.push(make_pair(s.first,s.second-1));
	}
	cout << res;
}
