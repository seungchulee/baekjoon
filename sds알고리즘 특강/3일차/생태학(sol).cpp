#include <map>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
int main(void)
{
	map<string, float> mm;
	char c[51];
	int cnt = 0;
	while (1)
	{
		cin.getline(c, 50);
		if (cin.eof() == true)
			break;
		if (mm.find(c) == mm.end())
		{
			mm.insert(make_pair(c, 1));
		}
		else
		{
			mm[c] += 1;
		}
		cnt++;
	}
	cout.precision(4);
	for (auto it = mm.begin(); it != mm.end(); it++)
	{
		cout << it->first << " ";
		printf("%.4f\n",it->second / cnt * 100);
		//cout << it->first << " " << it->second / cnt * 100<< '\n';
	}
}
