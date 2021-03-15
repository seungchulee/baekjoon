#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;
int arr[9][9];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M;
int maxs = -1;
void virus(){
    int tmp[9][9];
    queue<pair<int, int> > qq;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            tmp[i][j] = arr[i][j];
            if(tmp[i][j] == 2){
                qq.push(make_pair(i, j));
            }
        }
    }
    while(!qq.empty()){
        pair<int,int> p = qq.front();
        qq.pop();
        int x = p.first;
        int y = p.second;
        for(int i=0;i<4;i++){
            int ddx = x + dx[i];
            int ddy = y + dy[i];
            if (ddx >= N || ddy >= M || ddx < 0 || ddy < 0){
                continue;
            }
            if (tmp[ddx][ddy] == 0){
                tmp[ddx][ddy] = 2;
                qq.push(make_pair(ddx, ddy));
            }
        }
    }
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (tmp[i][j] == 0){
                count++;
            }
        }
    }
    maxs = max(maxs, count);
}
void wall(int index){
    if (index == 3){
        virus();
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if (arr[i][j] == 0){
                arr[i][j] = 1;
                wall(index+1);
                arr[i][j] = 0;
            }
        }
    }
}
int main(void)
{
    scanf("%d %d", &N, &M);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    wall(0);
    printf("%d",maxs);
}