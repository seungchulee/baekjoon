#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[101010];
int visit[101010];
int finish[101010];
int cnt;
void DFS(int x)
{
	visit[x]=1;
	if(visit[arr[x]]==-1)
		DFS(arr[x]);
	else if(finish[arr[x]]==-1)
	{
		for(int i=arr[x];i!=x;i=arr[i])
			cnt++;
		cnt++;
	}
	finish[x]=1;
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		memset(arr,0,sizeof(arr));
		memset(visit,-1,sizeof(visit));
		memset(finish,-1,sizeof(finish));
		for(int i=1;i<=n;i++)
		{
			cin >> arr[i];
		}
		cnt=0;
		for(int i=1;i<=n;i++)
			if(visit[i]==-1)
				DFS(i);
		cout << n-cnt << '\n';
	}
}	
