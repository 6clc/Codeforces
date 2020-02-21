#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
    int b;
    int p;
    int f;
    cin >> b >> p >> f;
    int h;
    int c;
    cin >> h >> c;

    if(h>c){
        int x = min(p, b/2);
        int y = min(f, (b - 2*x)/2);
        cout << x*h + y*c << endl;
    }else{
        int y = min(f, b/2);
        int x = min(p, (b - 2*y)/2);
       //  cout << x << " " << y << endl;
        cout << x*h + y*c << endl;
    }
}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
