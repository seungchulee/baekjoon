#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int prime[1010101];
int visit[1010101];
void make_prime()
{
	for(int i=2;i<1010101;i++)
	{
		if(prime[i]==-1)
			continue;
		prime[i]=1;
		for(int j=i+i;j<1010101;j+=i)
		{
			prime[j]=-1;
		}
	}

}
int main(void)
{
	int t;
	cin >> t;
	make_prime();
	while(t--)
	{
		int n,a,b;
		memset(visit,-1,sizeof(visit));
		cin >> n >> a >> b;
		queue<int> qq;
		qq.push(n);
		visit[n]=0;
		bool check=false;
		while(!qq.empty())
		{
			int x = qq.front();
			qq.pop();
			if(prime[x]==1 && x>=a && x<=b)
			{
				check=true;
				cout << visit[x] << '\n';
				break;
			}

			if(visit[x/2]==-1 && x>=4)
			{
				visit[x/2] = visit[x]+1;
				qq.push(x/2);
			}
			if(visit[x/3]==-1 && x>=6)
			{
				visit[x/3] = visit[x]+1;
				qq.push(x/3);
			}
			if(visit[x+1]==-1 && x+1<=1000000)
			{
				visit[x+1]=visit[x]+1;
				qq.push(x+1);
			}
			if(visit[x-1]==-1 && x-1>=2)
			{
				visit[x-1] = visit[x]+1;
				qq.push(x-1);
			}
		}
		if(check)
			continue;
		else
			cout << "-1\n";
	}
}
