#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
long long int to_union[100001];
long long int diff[100001];
long long int n[100001];
void init()
{
	for (int i = 0; i <= 100000; i++)
		to_union[i] = i;
}

long long int find(long long int a)
{
	if (to_union[a] == a)
		return to_union[a];
	else
	{
		long long int prev = find(to_union[a]);
		diff[a]+=diff[to_union[a]];
		return to_union[a]=prev;
	}
}
void Union(long long int a, long long int b,long long int w)
{
	long long int aa = find(a);
	long long int bb = find(b);
	
	if(aa!=bb)
	{
		if(n[bb]>=n[aa])
		{
			to_union[aa]=bb;
			long long int ndiff = diff[b]-diff[a]-w;
			diff[aa] += ndiff;
			n[bb]+=n[aa];
			n[aa]=1;
		}
		else
		{
			to_union[bb]=aa;
			long long int ndiff = diff[b]-diff[a]-w;
			diff[bb]-=ndiff;
			n[aa]+=n[bb];
			n[bb]=1;
		}
	}
	
}

int main(void)
{
	int N, M;
	while(1)
	{	
		scanf("%d %d", &N, &M);
		getchar();
		memset(n,1,sizeof(n));
		memset(diff,0,sizeof(diff));
		if (N == 0 && M == 0)
			break;
		init();
		for (int i = 0; i < M; i++)
		{
			char q;
			scanf("%c", &q);
			getchar();

			if (q == '!')
			{
				long long int a, b, c;
				scanf("%lld %lld %lld", &a, &b, &c);
				getchar();
				Union(a, b,c);
			}
			else
			{
				long long int a, b;
				scanf("%lld %lld", &a, &b);
				getchar();
				if (find(a) != find(b))
					printf("UNKNOWN\n");
				else
				{
					printf("%lld\n",diff[b]-diff[a]);
				}
			}

		}
	}
}
