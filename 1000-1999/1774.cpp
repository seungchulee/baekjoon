#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[1010];
int N,M;
double get_dis(int x, int y, int xx ,int yy)
{
	long long int left = pow(x-xx,2);
	long long int right = pow(y-yy,2);
	return sqrt(left+right);
}
int find(int a)
{
	if(arr[a]==a)
		return a;
	else
		return arr[a]=find(arr[a]);
}
	
void Union(int a, int b)
{
	int aa = find(a);
	int bb = find(b);
	arr[aa]=bb;
}
int main(void)
{
	for(int i=0;i<=1005;i++)
		arr[i]=i;

	scanf("%d %d",&N,&M);
	vector<pair<int,int> > vv;
	for(int i=0;i<N;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		vv.push_back(make_pair(x,y));
	}
	vector<pair<double,pair<int,int> > > vs;
	for(int i=0;i<vv.size()-1;i++)
	{
		int x = vv[i].first;
		int y = vv[i].second;
		for(int j=i+1;j<vv.size();j++)
		{
			int xx = vv[j].first;
			int yy = vv[j].second;
			double dis = get_dis(x,y,xx,yy);

			vs.push_back(make_pair(dis,make_pair(i,j)));
		}
	}
	double res=0;
	for(int i=0;i<M;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		x--;
		y--;
		Union(x,y);

	}
	sort(vs.begin(),vs.end());

	for(int i=0;i<vs.size();i++)
	{
		int x = vs[i].second.first;
		int y = vs[i].second.second;
		double w = vs[i].first;

		if(find(x)!=find(y))
		{

			
			res+=w;
			Union(x,y);
		}
	}
	printf("%.2lf",res);

}	
