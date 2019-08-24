#include <stdio.h>
#include <queue>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
int arr[100][2];
int visit[100];

int main(void)
{


	scanf("%d",&N);
	vector<pair<int, long long int> > v;
	for(int i=0;i<N;i++)
	{
		long long int num;
		scanf("%lld",&num);
		long long int tmp=num;
		int cnt=0;
		while(tmp%3==0)
		{
			tmp/=3;
			cnt++;
		}
		cnt=-cnt;
		v.push_back(pair<int,long long int>  (make_pair(cnt,num)));
		 
	}
	sort(v.begin(),v.end());
	for(int i=0;i<N;i++)
	{
		printf("%d ",v[i].second);
	}
}
