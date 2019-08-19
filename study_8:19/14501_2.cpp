#include <iostream>
#include <algorithm>
using namespace std;
const int inf = -100000000;
int t[21];
int p[21];
int n;
// go(day): day ㅂㅜㅌㅓ max profit
// go(1): 1~n max profit
int go(int day) {
    if (day == n+1) {
        return 0;
    }
    if (day > n+1) {
        return inf;
    }
    int t1 = go(day+1);
    // day ~ (day+t[day]-1) -> (day+t[day]) ~ n+1
    // --------------------    ------------------
    //       p[day]              go(day+t[day])
    int t2 = p[day] + go(day+t[day]);
    return max(t1,t2);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    int ans = go(1);
    cout << ans << '\n';
    return 0;
}