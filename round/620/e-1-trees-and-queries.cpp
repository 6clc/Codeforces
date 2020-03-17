#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
vector<int> G[maxn];
int n;
int h[maxn];
int f[19][maxn];

void dfs(int x){
    for(int i=0; i<G[x].size(); i++){
        int v = G[x][i];
        if(f[0][x] == v) continue;
        f[0][v] = x;
        h[v] = h[x] + 1;
        dfs(v);
    }
}

int lca(int a, int b){
    if(h[a] < h[b]) swap(a, b);

    for(int i=17; i>=0; i--){
        if((h[a] - h[b]) >> i){
            a = f[i][a];
        }
    }
    if(a==b) return a;

    for(int i=17; i>=0; i--){
        if(f[i][a] != f[i][b]){
            a = f[i][a];
            b = f[i][b];
        }
    }
    return f[0][a];
}

int dis(int a, int b){
    return h[a] + h[b] - h[lca(a, b)] * 2;
}
bool check(int a, int b){
    return a<=b && (a%2 == b%2);
}


int main(){
    int n;
    cin >> n;

    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(h, 0, sizeof(h));
    dfs(1);

    for(int i=1; i<=17; i++){
        for(int j=1; j<=n; j++){
            f[i][j] = f[i-1][f[i-1][j]];
        }
    }

    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if(check(dis(a, b), k) ||
        check(dis(a, x) + dis(y, b)+1, k) ||
        check(dis(a, y) + dis(x, b)+1, k))
        cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}