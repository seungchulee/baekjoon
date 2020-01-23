#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N,M;
vector<int> vv;
int visit[10101];
void func(int index, int cnt,vector<int> res)
{
	if(cnt==M)
	{
		for(int i=0;i<res.size();i++)
			printf("%d ",res[i]);
		printf("\n");
		return;
	}

	for(int i=0;i<N;i++)
	{
		if(visit[vv[i]]==1)
			continue;
		visit[vv[i]]=1;
		res.push_back(vv[i]);
		func(i+1,cnt+1,res);
		visit[vv[i]]=0;
		res.pop_back();
	}

	//res.push_back(vv[index]);

//	func(index+1,cnt+1,res);
//	res.pop_back();


}
int main(void)
{
	memset(visit,0,sizeof(visit));
	vector<int> res;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(x);
	}
	sort(vv.begin(),vv.end());
	func(0,0,res);
}
