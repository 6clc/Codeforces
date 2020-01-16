#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    vector<ll> dp(n+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++) dp[i] = (dp[i-1]*i)%m;

    ll ret = 0;
    for(int k=1; k<=n; k++){
        ret =  (ret + ((1ll*(n-k+1)*dp[k])%m*dp[n-k+1])%m)%m;
    }
    cout << ret << endl;
    return 0;
}
