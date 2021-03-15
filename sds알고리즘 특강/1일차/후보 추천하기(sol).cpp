#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <vector>
using namespace std;
struct info{
	int bunho;
	int choo;
	int idx;
};
bool operator<(info i1, info i2){
	if(i1.choo==i2.choo)
		return i1.idx > i2.idx;
	else
		return i1.choo > i2.choo;
};
int exist[101];
int main(void)
{
	int N;
	int std;
	memset(exist,-1,sizeof(exist));
	scanf("%d",&N);
	scanf("%d",&std);
	vector<info> vv;
	for(int i=0;i<std;i++)
	{
		int st;
		scanf("%d",&st);
		if(exist[st]!=-1)
		{
			for(int j=0;j<vv.size();j++)
			{
				if(vv[j].bunho==st)
				{
					vv[j].choo++;
					break;
				}
			}
			continue;
		}
		exist[st]=1;
		if(vv.size()<N)
		{

			struct info in;
			in.bunho=st;
			in.choo=1;
			in.idx=i;
			vv.push_back(in);
			continue;
		//	vv.push_back(
		}
		priority_queue<info> pq;
		for(int j=0;j<vv.size();j++)
		{
			pq.push(vv[j]);
		}

		struct info in = pq.top();
		for(int j=0;j<vv.size();j++)
		{
			if(vv[j].bunho==in.bunho)
			{
				exist[in.bunho]=-1;
				vv[j].bunho=st;
				vv[j].choo=1;
				vv[j].idx=i;
				break;
			}
		}


	}
	vector<int> ans;
	for(int i=0;i<vv.size();i++)
	{

		ans.push_back(vv[i].bunho);
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	
	
}
