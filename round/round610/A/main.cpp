#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){
    vector<pair<int, int>> q;
    int a, b, c, r;
    scanf("%d %d %d %d",&a, &b, &c, &r);
    if(a > b) swap(a, b);
    q.push_back(make_pair(a, 1));
    q.push_back(make_pair(b, -1));

    q.push_back(make_pair(c-r, 2));
    q.push_back(make_pair(c+r, -2));

    sort(begin(q), end(q));

    int ret = b-a;
    // 求交集的过程，自个儿减自个人
    if(abs(q[0].second) != abs(q[1].second)){
        ret -= q[2].first - q[1].first;
    }

    cout << ret << endl;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}
