#include <stdio.h>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int L, C;
char st[16];
void sol()
{
	vector<int> vv;
	for (int i = 0; i < L; i++)
	{
		vv.push_back(0);
	}
	for (int i = 0; i < C - L; i++)
	{
		vv.push_back(1);
	}
	do {
		int mo = 0;
		int ja = 0;
		queue<char> qq;
		for (int i = 0; i < vv.size(); i++)
		{
			if (vv[i] == 1)
				continue;
			if (st[i+1] == 'a' || st[i+1] == 'e' || st[i + 1] == 'i' || st[i + 1] == 'o' || st[i + 1] == 'u')
			{
				mo++;
			}
			else
				ja++;
			qq.push(st[i + 1]);
			//printf("%d ", vv[i]);
		}
		if (mo >= 1 && ja >= 2)
		{
			while (!qq.empty())
			{
				char st = qq.front();
				printf("%c", st);
				qq.pop();
			}
		}
		else
			continue;
		printf("\n");
	} while (next_permutation(vv.begin(),vv.end()));
	
}
int main(void)
{
	scanf("%d %d",&L, &C);

	for (int i = 0; i <= C; i++)
	{
		char ss;
		scanf("%c", &ss);
		if (ss == ' ')
		{
			i--;
			continue;
		}
		st[i] = ss;
	}

	sort(st+1, st + C+1);
	//printf("%s", st);
	sol();
}