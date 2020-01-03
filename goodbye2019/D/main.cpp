#include <iostream>
#include <cstdio>
#include <map>
using namespace std;



void solve(int n, int k){
    map<int, int> cnt;
    int maxx=0;

    for(int i=1; i<=k+1 ;i++){
        printf("?");
        for(int j=1; j<=k+1; j++) if(j!=i) printf(" %d", j);
        printf("\n"); fflush(stdout);

        int p, a;
        scanf("%d %d", &p, &a);
        cnt[a] = cnt[a] + 1; maxx = max(maxx, a);
    }
    printf("! %d\n", cnt[maxx]);fflush(stdout);

}

int main() {
    int n; int k;
    scanf("%d %d", &n, &k);
    solve(n, k);
    return 0;
}
