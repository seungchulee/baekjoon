#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
	int e,s,m;
	int ee=1,ss=1,mm=1;
	cin >> e >> s >> m;

	int cnt=1;
	while(1)
	{
		if(ee==e && ss==s && mm==m)
			break;
		ee=(ee+1)%15;
		if(ee==0)
			ee=15;
		ss=(ss+1)%28;
		if(ss==0)
			ss=28;
		mm=(mm+1)%19;
		if(mm==0)
			mm=19;
		//printf("%d ",cnt);
		cnt++;
	}
	cout << cnt;
}
