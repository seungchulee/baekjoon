#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int arr[51][51];
int M, N;
int dist = 10000000;
int main(void)
{
	vector<pair<int,int> > house;
	vector<pair<int, int> > chicken;
	scanf("%d %d", &N, &M);
	int ch = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &arr[i][j]);
			if(arr[i][j] == 1){
				house.push_back(make_pair(i, j));
			}
			if (arr[i][j] == 2){
				chicken.push_back(make_pair(i, j));
				ch++;
			}
		}
	}
	vector<int> check;
	for(int i=0;i<M;i++){
		check.push_back(0);
	}
	for(int i=0;i<ch-M;i++){
		check.push_back(1);
	}
	int chicken_dist = 10000000;
	do{
		int entire = 0;
		for(int i=0;i<house.size();i++){
			int house_min = 10000000;
			for(int j=0;j<chicken.size();j++){
				if(check[j] == 0){
					int dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
					house_min = min(house_min, dist);
				}
			}
			entire += house_min;
		}
		chicken_dist = min(chicken_dist, entire);
	}while(next_permutation(check.begin(), check.end()));
	printf("%d", chicken_dist);
	
}