#include <iostream>
using namespace std;
typedef long long ll;

void solve(){
    ll a;
    ll b;
    scanf("%lld %lld",&a, &b);

    ll x = (2*b - a);
    ll y = (2*a - b);

    if(x<0  || y<0){
        cout << "NO" << endl;
        return;
    }

    x = x%3;
    y = y%3;

    if(x==0 && y==0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
