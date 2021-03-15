#include <stdio.h>
#include <set>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int N;
char st[11][9];
int howmany = 0;
int used2[10];
int gap[27];
int ans=-1;
void DFS(int idx, vector<char> ch)
{
	if (idx == howmany)
	{
	/*	for (int i = 0; i < 10; i++)
		{
			printf("%d ", used2[i]);
		}
		printf("\n");*/
		/*for (int i = 0; i < 27; i++)
		{
			printf("%d ", gap[i]);
		}
		printf("\n");*/
		int num=0;
		for(int i=0;i<=idx;i++)
		{
			for(int j=0;j<strlen(st[i]);j++)
			{
				int k=1;
				for(int tt=0;tt<strlen(st[i])-j-1;tt++)
					k*=10;
				num+=gap[st[i][j]-'A']*k;
			}
		//	printf("!%d!",num);
		}
		//printf("\n");
		if(ans<num)
			ans=num;
		return;
	}
	

	for (int j = 9; j >= 0; j--)
	{
		if (used2[j] == 0)
			continue;
		gap[ch[idx] - 'A'] = j;
		used2[j] = 0;
		DFS(idx + 1, ch);
		used2[j] = -1;
		gap[ch[idx] - 'A'] = -1;
	}

}
int main(void)
{
	memset(gap, -1, sizeof(gap));
	memset(used2, -1, sizeof(used2));
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", st[i]);
	}
	set<char> character;
	for (int i = 0; i < N; i++)
	{
		for(int j=0;j<strlen(st[i]);j++)
			character.insert(st[i][j]);
	}
	howmany = character.size();
	vector<char> charac(character.begin(), character.end());
	
	DFS(0,charac);
	printf("%d",ans);
}
