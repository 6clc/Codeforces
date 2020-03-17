#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int n, m, k;

vector<int> G[maxn];
vector<int> sp(maxn);
int dis[2][maxn];
int vis[maxn];

void bfs(int x, int st){
    memset(vis, 0, sizeof(vis));

    queue<int> q;
    vis[st] = 1;
    dis[x][st] = 0;
    q.push(st);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(auto nxt:G[cur]){
            if(vis[nxt] == 0){
                q.push(nxt);
                vis[nxt] = 1;
                dis[x][nxt] = dis[x][cur] + 1;
            }
        }
    }
}
int main(){
    scanf("%d %d %d", &n, &m, &k);

    for(int i=0; i<k; i++){
        scanf("%d", &sp[i]);
    }
    for(int i=0; i<m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bfs(0, 1);
    bfs(1, n);

    vector<pair<int, int>> sp2;
    for(int i=0; i<k; i++){
        sp2.push_back({dis[0][sp[i]] - dis[1][sp[i]], sp[i]});
    }
    sort(begin(sp2), end(sp2));

    int ret = 0;
    int tmp = 0;
    for(int i=0; i<k; i++){
        if(i){
            ret = max(ret, tmp + dis[1][sp2[i].second] + 1);
        }
        tmp = max(tmp, dis[0][sp2[i].second]);
    }
    ret = min(ret, dis[0][n]);

    cout << ret << endl;

    return 0;
}