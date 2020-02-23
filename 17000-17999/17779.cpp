#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N;
int arr[21][21];
int divs[21][21];
int dd[21];
int vs[21];
vector<int> vv;
int mins = 100000000;
bool possible(int x, int y)
{
	if(x+vv[0]+vv[1]>=N)
		return false;
	if(y-vv[0]<0)
		return false;
	if(y+vv[1]>=N)
		return false;

	return true;
}
void divide(int x, int y)
{
	if(!possible(x,y))
		return;
	memset(divs,-1,sizeof(divs));
	divs[x][y]=5;
	for(int i=1;i<=vv[0];i++)
		divs[x+i][y-i]=5;
	for(int i=1;i<=vv[1];i++)
		divs[x+i][y+i]=5;
	int nx = x+vv[0];
	int mx = x+vv[1];
	int ny = y-vv[0];
	int my = y+vv[1];
	for(int i=1;i<=vv[1];i++)
		divs[nx+i][ny+i]=5;
	for(int i=1;i<=vv[0];i++)
		divs[mx+i][my-i]=5;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(i==x && j==y)
				break;
			if(i==x+vv[0]+vv[1] && j==y+vv[1]-vv[0])
				break;
			if(divs[i][j]==5)
			{
				for(int a=1;a<=N;a++)
				{
					if(divs[i][j+a]==5)
						break;
					divs[i][j+a]=5;
				}
				break;
			}
		}
	}

	for(int i=0;i<nx;i++)
	{
		for(int j=0;j<=y;j++)
		{
			if(divs[i][j]==5)
				break;
			divs[i][j]=1;
		}		
	}
	for(int i=0;i<=mx;i++)
	{
		for(int j=y+1;j<N;j++)
		{
			if(divs[i][j]==5)
				continue;
			divs[i][j]=2;
		}
	}
	for(int i=nx;i<N;i++)
	{
		for(int j=0;j<ny+vv[1];j++)
		{
			if(divs[i][j]==5)
				break;
			divs[i][j]=3;
		}
	}
	for(int i=mx+1;i<N;i++)
	{
		for(int j=ny+vv[1];j<N;j++)
		{
			if(divs[i][j]==5)
				continue;
			divs[i][j]=4;
		}
	}
	int ones = 0;
	int twos = 0;
	int threes = 0;
	int fours = 0;
	int fives = 0;

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{

			if(divs[i][j]==1)
				ones+=arr[i][j];
			if(divs[i][j]==2)
				twos+=arr[i][j];
			if(divs[i][j]==3)
				threes+=arr[i][j];
			if(divs[i][j]==4)
				fours+=arr[i][j];
			if(divs[i][j]==5)
				fives+=arr[i][j];
		}

	}
	vector<int> res;
	res.push_back(ones);
	res.push_back(twos);
	res.push_back(threes);
	res.push_back(fours);
	res.push_back(fives);
	sort(res.begin(),res.end());
	int mm = res[res.size()-1]-res[0];
	mins=min(mins,mm);

}
void func(int idx, int cnt)
{
	if(cnt==2)
	{
		for(int i=0;i<N-1;i++)
		{
			for(int j=1;j<N-1;j++)
			{
				divide(i,j);
			}
		}
		return;
	}
	for(int i=1;i<N;i++)
	{

		vv.push_back(dd[i]);
		func(idx+1,cnt+1);
		vv.pop_back();

	}
}
int main(void)
{
	scanf("%d",&N);
	memset(vs,-1,sizeof(vs));
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=1;i<21;i++)
		dd[i]=i;
	func(1,0);
	printf("%d",mins);
}
