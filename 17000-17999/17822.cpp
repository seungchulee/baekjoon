#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
deque<deque<int> > dq;
int N,M,T;
void move(int x, int d, int k)
{
	for(int i=x;i<=N;i+=x)
	{
		if(d==0)
		{
			for(int j=0;j<k;j++)
			{
				int tmp = dq[i][M-1];
				dq[i].pop_back();
				dq[i].push_front(tmp);
			}
		}
		else
		{
			for(int j=0;j<k;j++)
			{
				int tmp = dq[i][0];
				dq[i].pop_front();
				dq[i].push_back(tmp);
			}
		}
	}
}
void check()
{
	bool flag = true;
	vector<vector<int> > vv;
	vector<vector<int> > vs;
	vv.resize(N+1);
	vs.resize(M);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
			vv[i].push_back(dq[i][j]);
	}
	for(int j=0;j<M;j++)
	{
		for(int i=1;i<=N;i++)
			vs[j].push_back(dq[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(vv[i][j]==-1)
				continue;
			if(vv[i][j]==vv[i][(j+1)%M])
			{

				flag=false;
				dq[i][j]=-1;
				dq[i][(j+1)%M]=-1;
			}
		}
	}

	for(int j=0;j<M;j++)
	{
		for(int i=1;i<=N;i++)
		{
			if(vs[j][i-1]==-1)
				continue;
			if(vs[j][i-1]==vs[j][i])
			{
				if(i==N)
					continue;
				flag=false;
				dq[i][j]=-1;
				dq[i+1][j]=-1;
			}
		}
	}

	if(flag==true)
	{
		int cnt=0;
		int res=0;
		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(dq[i][j]!=-1)
				{
					res+=dq[i][j];
					cnt++;
				}
			}
		}
		float avg = (float)res/cnt;

		for(int i=1;i<=N;i++)
		{
			for(int j=0;j<M;j++)
			{
				if(dq[i][j]==-1)
					continue;
				if(dq[i][j] < avg)
					dq[i][j]++;
				else if(dq[i][j]>avg)
					dq[i][j]--;
			}
		}

		return;
	}
	else
	{

		return;
	}

}
int main(void)
{

	scanf("%d %d %d",&N,&M,&T);
	dq.resize(N+1);
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			int x;
			scanf("%d",&x);
			dq[i].push_back(x);
		}
	}
	

	for(int i=0;i<T;i++)
	{
		int x, d, k;
		scanf("%d %d %d",&x,&d,&k);
		move(x,d,k);

		check();

	}
	int res=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(dq[i][j]!=-1)
				res+=dq[i][j];
		}
	}
	printf("%d",res);
}
