#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    while(~scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f)){
        int a1 = min(a, d);
        int a2 = min(min(b, c), d);
        int res;
        if(e>f){
            a2 = min(a2, d-a1);
        }else{
            a1 = min(a1, d-a2);
        }
        res = a2 * f + a1 * e;
        cout << res << endl;
    }

    return 0;
}
