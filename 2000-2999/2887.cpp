#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
bool sort1(const pair<pair<int,int>,pair<int,int> > &p1,const pair<pair<int,int>,pair<int,int> > &p2)
{
	return p1.first.first < p2.first.first;
}
bool sort2(const pair<pair<int,int>,pair<int,int> > &p1,const pair<pair<int,int>,pair<int,int> > &p2)
{
	return p1.second.first < p2.second.first;
}
bool sort3(const pair<pair<int,int>,pair<int,int> > &p1,const pair<pair<int,int>,pair<int,int> > &p2)
{
	return p1.second.second < p2.second.second;
}
int arr[101010];
void init()
{
	for(int i=0;i<100011;i++)
		arr[i]=i;
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
	init();
	int N;
	scanf("%d",&N);
	vector<pair<pair<int,int>,pair<int,int> > > vv;
	for(int i=0;i<N;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vv.push_back(make_pair(make_pair(a,i+1),make_pair(b,c)));
	}
	sort(vv.begin(),vv.end(),sort1);
	vector<pair<int,pair<int,int> > > vs;
	
	for(int i=0;i<vv.size()-1;i++)
	{
		int from = vv[i].first.second;
		int to = vv[i+1].first.second;
		int weight = vv[i+1].first.first-vv[i].first.first;
		vs.push_back(make_pair(weight,make_pair(from,to)));	
	}

	sort(vv.begin(),vv.end(),sort2);
	for(int i=0;i<vv.size()-1;i++)
	{
		int from = vv[i].first.second;
		int to = vv[i+1].first.second;
		int weight = vv[i+1].second.first-vv[i].second.first;
		vs.push_back(make_pair(weight,make_pair(from,to)));	
	}

	sort(vv.begin(),vv.end(),sort3);
	for(int i=0;i<vv.size()-1;i++)
	{
		int from = vv[i].first.second;
		int to = vv[i+1].first.second;
		int weight = vv[i+1].second.second-vv[i].second.second;
		vs.push_back(make_pair(weight,make_pair(from,to)));	
	}
	sort(vs.begin(),vs.end());
	int res=0;
	for(int i=0;i<vs.size();i++)
	{
		int ww = vs[i].first;
		int from = vs[i].second.first;
		int to = vs[i].second.second;
		if(find(from)!=find(to))
		{
			Union(from,to);
			res+=ww;
		}
	}
	printf("%d",res);
}
