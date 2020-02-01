#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<pair<float,float> > vv;
int arr[101];
float get_dis(float x, float y, float xx, float yy)
{
	return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
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
	int N;
	scanf("%d",&N);
	for(int i=0;i<=100;i++)
		arr[i]=i;
	for(int i=0;i<N;i++)
	{
		float x,y;
		scanf("%f %f",&x,&y);
		vv.push_back(make_pair(x,y));
	}
	vector<pair<float,pair<int,int> > > vs;
	for(int i=0;i<vv.size()-1;i++)
	{
		int x = vv[i].first;
		int y = vv[i].second;
		for(int j=i+1;j<vv.size();j++)
		{
			int xx = vv[j].first;
			int yy = vv[j].second;
			float dis = get_dis(x,y,xx,yy);
			vs.push_back(make_pair(dis,make_pair(i,j)));
		}
	}
	float res=0;
	sort(vs.begin(),vs.end());
	for(int i=0;i<vs.size();i++)
	{
		if(find(vs[i].second.first)!=find(vs[i].second.second))
		{
			Union(vs[i].second.first,vs[i].second.second);
			res+=vs[i].first;
		}
			
	}
	printf("%.2f",res);
}
