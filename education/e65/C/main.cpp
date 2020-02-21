#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAXN = int(5e5+5);
int root[MAXN];
int cnt[MAXN];

int find_root(int r){
    while (r!=root[r]){
        root[r] = root[root[r]];
        r = root[r];
    }
    return r;
}

void unit(int u, int v){
    int ra = find_root(u);
    int rb = find_root(v);
    if(ra == rb) return;

    if(ra > rb) swap(ra, rb);
    root[rb] = ra;
    cnt[ra] = cnt[ra] + cnt[rb];
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    int m;
    cin >> n >> m;

    for(int i=0; i<n; i++) { cnt[i] = 1; root[i] = i; }

    for(int i=0; i<m; i++){
        int k;
        cin >> k;
        int u;
        int v;
        for(int j=0; j<k; j++){
            if(j==0) {cin >> u; continue;}
            cin >> v;
            // cout << u << " " << v << endl;
            unit(u, v);
            u = v;
        }
    }
    for(int i=1; i<=n; i++){
        int fa = find_root(i);
        if(i<n)
        cout << cnt[fa] << " ";
        else
            cout << cnt[fa];
    }
    cout << endl;

    return 0;
}
