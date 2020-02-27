#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
int arr[1010];
int visit[1010];
void DFS(int x)
{
	visit[x]=1;

	if(visit[arr[x]]==-1)
	{
		DFS(arr[x]);
	}
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(arr,-1,sizeof(arr));
		memset(visit,-1,sizeof(visit));
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> arr[i];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(visit[i]==-1)
			{
				DFS(i);
				cnt++;
			}

		}
		cout << cnt << '\n';
	}

}
