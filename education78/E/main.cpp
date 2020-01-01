#include <iostream>
#include <vector>
#include <map>

using namespace std;
const int maxn = 500000 + 5;
int ll[maxn];
int rr[maxn];
int cnt;
vector<vector<int>> graph;
int visit[maxn];


void dfs(int a, int fa){
    visit[a] = 1;
    for(int i=0; i<graph[a].size(); i++){
        int b = graph[a][i];
        if(b == fa) continue; // 树一个点只有一条边
        ll[b] = cnt++;  // 左由父定
    }
    rr[a] = cnt++; // 右由子定

    for(int i=graph[a].size()-1; i>=0; i--){
        int b = graph[a][i];
        if(b == fa) continue;
        dfs(b, a);
    }
}
void solve(int n){
    graph = vector<vector<int>>(n+1);
    cnt = 1;
    for(int i=0; i<n-1; i++){
        int a, b;
        scanf("%d %d",&a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ll[1] = cnt++;
    dfs(1, -1);
    for(int i=1; i<=n ;i++){
        cout<<ll[i]<<" "<<rr[i]<<endl;
    }
}

int main() {
    int n;
    while(~scanf("%d", &n))
        solve(n);
}
