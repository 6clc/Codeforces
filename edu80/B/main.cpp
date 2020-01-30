#include <iostream>
#include <cstdio>
using namespace std;
typedef  long long ll;

void solve(){
    ll a;
    ll b;
    scanf("%lld %lld",&a, &b);
    ll cnt = 0;
    ll cur = 9;
    while(cur <= b){
        cur = cur*10 + 9;
        cnt += 1;
    }
    cout << cnt*a << endl;

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
