#include <stdio.h>
#include <queue>
#include <utility>
#include <set>
using namespace std;
int A,B,C;
bool result=false;
set <pair<pair<int,int>,int> > ss;
void BFS()
{

	queue<pair<pair<int,int>,int> > qq;
	qq.push(make_pair(make_pair(A,B),C));
	ss.insert(make_pair(make_pair(A,B),C));
	int cnt=0;
	while(!qq.empty())
	{
		cnt++;
		if(cnt>5000)
			break;
		pair<pair<int,int>,int> s = qq.front();
		int a=s.first.first;
		int b=s.first.second;
		int c=s.second;
		//!printf("!");
		qq.pop();

		if(a==b && b==c && a==c)
		{
			result=true;
			break;
		}

		if(a>b)
		{
			int tmp_a = a-b;
			int tmp_b = b+b;
			if(ss.find(make_pair(make_pair(tmp_a,tmp_b),c))==ss.end())
				qq.push(make_pair(make_pair(tmp_a,tmp_b),c));
		}
		if(a<b)
		{
			int tmp_a=a+a;
			int tmp_b=b-a;
			if(ss.find(make_pair(make_pair(tmp_a,tmp_b),c))==ss.end())
				qq.push(make_pair(make_pair(tmp_a,tmp_b),c));
		}
		if(b<c)
		{
			int tmp_b=b+b;
			int tmp_c=c-b;
			if(ss.find(make_pair(make_pair(a,tmp_b),tmp_c))==ss.end())
				qq.push(make_pair(make_pair(a,tmp_b),tmp_c));
		}
		if(b>c)
		{
			int tmp_b=b-c;
			int tmp_c=c+c;
			if(ss.find(make_pair(make_pair(a,tmp_b),tmp_c))==ss.end())
				qq.push(make_pair(make_pair(a,tmp_b),tmp_c));

		}
		if(a<c)
		{
			int tmp_a=a+a;
			int tmp_c=c-a;
			if(ss.find(make_pair(make_pair(tmp_a,b),tmp_c))==ss.end())
				qq.push(make_pair(make_pair(tmp_a,b),tmp_c));
		}
		if(a>c)
		{
			int tmp_a=a-c;
			int tmp_c=c+c;
			if(ss.find(make_pair(make_pair(tmp_a,b),tmp_c))==ss.end())
				qq.push(make_pair(make_pair(tmp_a,b),tmp_c));
		}

	}
	if(result==true)
		printf("1");
	else
		printf("0");
}
int main(void)
{
	scanf("%d %d %d",&A,&B,&C);
	BFS();
}
