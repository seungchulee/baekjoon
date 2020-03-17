#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	stack<int> s;
	int start=1;
	while(!q.empty())
	{
		if(q.front()==start)
		{
			start++;
			q.pop();
		}
		else if(s.size()!=0 && s.top()==start)
		{
			start++;
			s.pop();
		}
		else
		{
			s.push(q.front());
			q.pop();
		}
	}
	bool check=true;
	while(!s.empty())
	{
		if(s.top()!=start)
			check=false;
		start++;
		s.pop();
	}
	if(check==true)
		cout << "Nice";
	else
		cout << "Sad";
}
