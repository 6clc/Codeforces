#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;
int n, q, f[18][maxn], h[maxn];
vector<int>G[maxn];

void dfs(int x){
    for(int i=0; i<G[x].size(); i++){
        int v = G[x][i];
        if(v == f[0][x]) continue;
        f[0][v] = x;
        h[v] = h[x] + 1;
        dfs(v);
    }
}

int lca(int x, int y){
    if(h[x] < h[y]){
        swap(x, y);
    }

    // 统一 x 和 y的高度, 高度差为i；
    for(int i=17; i>=0; i--){
        if((h[x] - h[y]) >> i){
            x = f[i][x];
        }
    }

    if(x==y) return x;

    // 从最高处开始，遍历
    for(int i=17; i>=0; i--){
        if(f[i][x] != f[i][y]){
            x = f[i][x];
            y = f[i][y];
        }
    }
    return f[0][x];
}

int dis(int x, int y){
    return h[x] + h[y] - h[lca(x, y)]*2;
}


bool check(int x, int y){
    return y >= x && x%2 == y%2;
}

int main(){
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 打表： 只挑一格
    dfs(1);

    // 打完所有表
    for(int i=1; i<=17; i++){
        for(int j=1; j<=n; j++){
            f[i][j] = f[i-1][f[i-1][j]];
        }
    }
    cin >> q;
    for(int i=0; i<q; i++){
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >>k;
        if(check(dis(a, b), k) || 
            check(dis(a, x) + dis(y, b) + 1, k)||
            check(dis(a, y) + dis(x, b) + 1, k))
            cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }
    }
}