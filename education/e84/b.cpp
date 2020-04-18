#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, m;
    cin >> n >> m;
    
    ll t = m/2 + 1;
    
    double ret = 0.;
    double cur = 1.;
    double j = 0;
    while(true){
        if(j>=m) break;
        if(j != 0) {
            double a = (m-j+2)/(m+n-j+2);
            double b = (m-j+1) / (m+n-j+1);
            cur = cur * a * b;
        }

        ret += cur*n/(m+n-j);
        j+=2;
    }
    
    printf("%.4f\n", ret);
    return 0;
}