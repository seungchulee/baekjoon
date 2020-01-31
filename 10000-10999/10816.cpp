#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(void)
{
	int N;
	scanf("%d",&N);
	vector<int> vv;
	for(int i=0;i<N;i++)
	{
		int x;
		scanf("%d",&x);
		vv.push_back(x);

	}
	sort(vv.begin(),vv.end());
	int M;
	scanf("%d",&M);

	for(int i=0;i<M;i++)
	{
		int x;
		scanf("%d",&x);
		int lower = lower_bound(vv.begin(),vv.end(),x)-vv.begin();
		int upper = upper_bound(vv.begin(),vv.end(),x)-vv.begin();
		if(lower==upper)
			printf("0 ");
		else
			printf("%d ",upper-lower);

	}
}

