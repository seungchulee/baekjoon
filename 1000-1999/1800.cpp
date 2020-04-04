#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int n,p,k;
int dist[1010];
vector<vector<pair<int,int> > > vv;

int check(int x)
{
	for(int i=0;i<1010;i++)
		dist[i]=10000000;
	dist[1]=0;
	priority_queue<pair<int,int > , vector<pair<int,int> > , greater<pair<int,int> > > pq;

	pq.push(make_pair(0,1));
	while(!pq.empty())
	{
		int ww = pq.top().first;
		int from = pq.top().second;
		pq.pop();
		if(ww > dist[from])
			continue;
		for(int i=0;i<vv[from].size();i++)
		{
			int to = vv[from][i].second;
			int nxtww;
			if(vv[from][i].first > x)
				nxtww = ww + 1;
			else
				nxtww = ww;
			if(nxtww < dist[to])
			{
				dist[to] = nxtww;
				pq.push(make_pair(nxtww, to));
			}
		}
	}

	if(dist[n] <= k )
		return 1;
	else
		return 0;
	
}
int main(void)
{
	cin >> n >> p >> k;
	vv.resize(n+1);
	for(int i=0;i<p;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		vv[x].push_back(make_pair(w,y));
		vv[y].push_back(make_pair(w,x));
	}	

	int left = 0;
	int right = 100000000;
	int ans = -1;
	while(left<=right)
	{
		int mid = (left+right)/2;
		if(check(mid)==1)
		{
			ans = mid;
			right = mid-1;
		}
		else
			left = mid+1;
	}
	cout << ans;
}		
