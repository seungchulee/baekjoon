#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int N;
char st[11][10];
int alpha[27];
int main(void)
{
	memset(alpha,0,sizeof(alpha));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%s",st[i]);
		for(int j=0;j<(int)strlen(st[i]);j++)
		{
			int k=1;
			for(int t=0;t<(int)strlen(st[i])-j-1;t++)
			{
				k*=10;
			}
			alpha[st[i][j]-'A']+=k;
		}
	}
	
	vector<int> vv;
	for(int i=0;i<26;i++)
	{
		if(alpha[i]!=0)
			vv.push_back(alpha[i]);
	}
	sort(vv.begin(),vv.end());
	int mul=9;
	int ans=0;
	for(int i=(int)vv.size()-1;i>=0;i--)
	{
		ans+=mul*vv[i];
		mul--;
			
	}
	printf("%d",ans);
}
