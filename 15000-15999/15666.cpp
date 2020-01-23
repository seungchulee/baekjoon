#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
vector<int> vv;
int check[10];
void func(int index, int cnt,vector<int> res)
{
	if(cnt==M)
	{
		for(int i=0;i<res.size();i++)
			printf("%d ",res[i]);
		printf("\n");
		return;
	}
	int ch[10001];
	memset(ch,-1,sizeof(ch));
	for(int i=0;i<N;i++)
	{
		if(ch[vv[i]]>=0 || vv[index-1]>vv[i])
			continue;

		ch[vv[i]]++;
		res.push_back(vv[i]);
		func(i+1,cnt+1,res);

		res.pop_back();
	}
}
int main(void)
{
	scanf("%d %d",&N,&M);
	memset(check,-1,sizeof(check));
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(x);
	}
	sort(vv.begin(),vv.end());
	vector<int> res;
	func(0,0,res);
}

