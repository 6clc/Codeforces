#include <iostream>
#include <cstdio>
using namespace std;

void solve(){
    int a;
    int b;
    scanf("%d %d", &a, &b);

    int x = b / a;
    int m = b % a;
    cout << x*x*(a-m) + (x+1)*(x+1)*m << endl;



}


int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    scanf("%d", &n);
    while(n--) solve();
    return 0;
}
