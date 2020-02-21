#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const int maxn = 200000 + 2;
vector<int> root(maxn);
vector<int> cnt(maxn);
int ret;


void init(int n){
    for(int i=0; i<n; i++) root[i] = i;
}

int find_root(int r){
    while(r!=root[r]) r=root[r];
    return r;
}

void unit(int u, int v){
    int root_u = find_root(u);
    int root_v = find_root(v);
    if(root_u == root_v) return;
    if(root_u < root_v) swap(root_u, root_v);
    root[root_u] = root_v;
    cnt[root_v] += cnt[root_u];
    cnt[root_u] = 0;
    // ret --;

}


int main() {
    int n;
    while(~scanf("%d", &n)){
        init(n+26);
        ret = n;
        for(int i=0; i<26+n; i++) {
            if(i<26) cnt[i] = 0;
            else cnt[i] = 1;
        }
        for(int i=0; i<n; i++){
            string tmp;
            cin >> tmp;

            for(auto ch:tmp){
                int u = ch-'a';
                int v = i+26;
                unit(u, v);
            }
        }

        ret = 0;
        for(int i=0; i<26+n; i++)
            if(cnt[i]) ret+=1;

        printf("%d\n", ret);
    }
    return 0;
}
