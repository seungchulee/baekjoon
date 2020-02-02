#include <stdio.h>
#include <vector>
using namespace std;
int n,k;
vector<vector<int> > vs;
void func(int sum,vector<int> vv)
{
	if(sum>n)
		return;
	if(sum==n)
	{
		vs.push_back(vv);
		return;
	}
	vv.push_back(1);
	func(sum+1,vv);
	vv.pop_back();
	vv.push_back(2);
	func(sum+2,vv);
	vv.pop_back();
	vv.push_back(3);
	func(sum+3,vv);
	vv.pop_back();
}
int main(void)
{
	scanf("%d %d",&n,&k);
	vector<int> vv;
	func(0,vv);
	if(vs.size()<k)
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<vs[k-1].size();i++)
	{
		printf("%d",vs[k-1][i]);
		if(i!=vs[k-1].size()-1)
			printf("+");
	}	

}
