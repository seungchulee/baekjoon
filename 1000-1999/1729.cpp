#include <stdio.h>
#include <utility>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int L, C;
char arr[16];
void check(int index, int start){
    vector<int> visit;
    for(int i=0;i<L;i++){
        visit.push_back(0);
    }
    for(int i=0;i<C-L;i++){
        visit.push_back(1);
    }
    do{
        int mo = 0;
        int ja = 0;
        for(int i=0;i<C;i++){
            if(visit[i] == 0){
                if(arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'){
                    mo++;
                } else {
                    ja++;
                }
            }
        }
        if(mo >= 1 && ja>=2){
            for(int i=0;i<C;i++){
                if(visit[i] == 0){
                    printf("%c",arr[i]);
                }
            }
            printf("\n");
        }
    }while(next_permutation(visit.begin(), visit.end()));
}
int main(void){
    scanf("%d %d", &L, &C);
    for(int i=0;i<C;i++){
        cin >> arr[i];
    }
    sort(arr, arr+C);
    check(0, 0);
}