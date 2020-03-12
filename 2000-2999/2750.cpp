#include <stdio.h>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	priority_queue<int,vector<int>,greater<int> > qq;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		qq.push(x);
	}
	while(!qq.empty())
	{
		cout << qq.top() << '\n';
		qq.pop();
	}
}
