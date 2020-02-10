#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int main(void)
{
	scanf("%d",&N);
	vector<int> vv;
	for(int i=0;i<N;i++)
	{	
		int x;
		scanf("%d",&x);
		vv.push_back(x);
	}
	int maxs=-1;
	sort(vv.begin(),vv.end());
	do{
		int tmp=0;
		for(int i=0;i<vv.size()-1;i++)
		{
			tmp+=abs(vv[i]-vv[i+1]);
		}
		maxs=max(maxs,tmp);
	}while(next_permutation(vv.begin(),vv.end()));
	printf("%d",maxs);
}

