#include <stdio.h>
#include <queue>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
int arr[16][16];
int N,M,D;
vector<pair<int,int> > enemy;
bool sort1(const pair<int,pair<int,int> > &p1,const pair<int,pair<int,int> > &p2)
{
	return p1.second.second < p2.second.second;
}
int maxs=-1;
void calculate(vector<int> ar)
{
	int tmp[16][16];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			tmp[i][j]=arr[i][j];
		}
	}
	vector<pair<int,int> > bow;
	for(int i=0;i<ar.size();i++)
	{
		if(ar[i]==1)
			bow.push_back(make_pair(N,i));
	}
	vector<pair<int,int> > res;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<bow.size();j++)
		{
			int bow_i = bow[j].first-i;
			int bow_j = bow[j].second;
			vector<pair<int, pair<int,int> > > vs;
			for(int k=0;k<enemy.size();k++)
			{
				if(enemy[k].first>=bow_i)
					continue;
				int dis = abs(enemy[k].first-bow_i)+abs(enemy[k].second-bow_j);
				if(dis<=D)
				{
					vs.push_back(make_pair(dis,make_pair(enemy[k].first,enemy[k].second)));
				}
			}

			sort(vs.begin(),vs.end());

			if(vs.size()==0)
				continue;
			
			int min_dis = 10000000;
			int ii,jj;
			for(int k=0;k<vs.size();k++)
			{
				if(tmp[vs[k].second.first][vs[k].second.second]==0)
					continue;
				if(vs[k].first==min_dis)
				{
					if(vs[k].second.second<jj)
					{
						ii=vs[k].second.first;
						jj=vs[k].second.second;
					}
				}
				if(vs[k].first<min_dis)
				{
					min_dis=vs[k].first;
					ii=vs[k].second.first;
					jj=vs[k].second.second;
				}
			}
			if(min_dis==10000000)
				continue;
			res.push_back(make_pair(ii,jj));
		}
		for(int j=0;j<res.size();j++)
			tmp[res[j].first][res[j].second]=0;

	}
	set<pair<int,int> > ss;
	for(int i=0;i<res.size();i++)
	{
		ss.insert(make_pair(res[i].first,res[i].second));
	}	
	maxs=max(maxs,(int)ss.size());
}
void func()
{
	vector<int> ar;
	for(int i=0;i<M-3;i++)
		ar.push_back(0);
	for(int i=0;i<3;i++)
		ar.push_back(1);
	do{
		calculate(ar);
	}while(next_permutation(ar.begin(),ar.end()));
}	
int main(void)
{
	scanf("%d %d %d",&N,&M,&D);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1)
				enemy.push_back(make_pair(i,j));
		}
	}
	func();
	printf("%d",maxs);
}
