#include <iostream>
#include <cstdio>
#include <cmath>
typedef  long long ll;
using namespace std;

ll cal(ll x, ll d){
    return x + (d+x)/(x+1);
    // return x + ceil((float(d) / (x+1)));
}
void solve(){
    ll n;
    ll d;
    scanf("%lld %lld",&n, &d);
    if(d<=n){
        cout << "YES" << endl;
        return;
    }

    ll t = sqrt(d);
    for(int i=0; i<=t + 10000; i++){
        if(cal(i, d) <= n) {cout << "YES" << endl; return;}
    }
//    for(int i=0; i<10000; i++){
//        if(cal(t+i, d) <= n) {cout<< "YES" << endl; return;}
//    }
    cout << "NO" << endl;
}
int main() {
   //  std::cout << "Hello, World!" << std::endl;
   int T;
   cin >> T;
   while(T--){
       solve();
   }
    return 0;
}
