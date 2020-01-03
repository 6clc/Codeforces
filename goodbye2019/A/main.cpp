#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        int x;
        while (a--){
            cin >> x;
            if(x==n) cout << "YES" << endl;
        }
        while (b--){
            cin >> x;
            if(x==n) cout << "NO" << endl;
        }
    }
    return 0;
}
