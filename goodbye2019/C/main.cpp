#include <iostream>
#include <cstdio>

typedef long long ll;
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);

    ll sum=0;
    ll xsum=0;
    while(n--){
        int a;
        scanf("%lld", &a);
        xsum ^= a;
        sum += a;
    }

    printf("%d\n%lld %lld\n", 2, xsum, sum+xsum);


}

int main() {
    int t;
    scanf("%d", &t);
    while(t--)
        solve();
    return 0;
}
