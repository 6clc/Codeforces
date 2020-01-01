#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 1e6+5;
int root[maxn];
vector<pair<int, int>> p;
pair<int, int> a[maxn];

int find_root(int r){
    return r == root[r] ? r : root[r] = find_root(root[r]) ;
}

void solve(int n){

    for(int i=1; i<=n; i++){
        root[i] = i;
        scanf("%d %d", &a[i].first, &a[i].second);
        p.push_back(make_pair(a[i].first, i));
        p.push_back(make_pair(a[i].second, -i));
    }

    sort(p.begin(), p.end());
    set<pair<int, int>> S;
    int cnt = 0;
    for(int i=0; i<p.size(); i++){
        if(p[i].second > 0){
            S.insert(make_pair(-p[i].first, p[i].second));
        }else{
            for(auto x:S) {
                int idx = -p[i].second;
                if (-x.first == a[idx].first) {
                    break;
                }

                if(cnt == n-1){
                    printf("NO\n");
                    return;
                }
                int ra = find_root(idx);
                int rb = find_root(x.second);
                if (ra == rb){
                    printf("NO\n");
                    return;
                }
                root[ra] = rb;
                cnt += 1;
            }
            S.erase(make_pair(-a[-p[i].second].first, -p[i].second));
        }
    }
    if(cnt == n-1 ) printf("YES\n");
    else printf("NO\n");

}
int main() {
    int n = 0;
    scanf("%d", &n);
    solve(n);
    return 0;
}
