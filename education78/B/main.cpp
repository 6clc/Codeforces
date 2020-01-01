#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
#define MP(a, b, c) (make_pair(make_pair(a, b), c))
void solve(){
    int a;
    int b;
    scanf("%d %d",&a, &b);
    if(a == b){
        printf("0\n");
        return;
    }
    if(a<b) swap(a, b);

    int target = a - b;
    for(int i=1; ; i++){
        int cur = (i*(i+1)) / 2;
        if(cur >= target && target%2 == cur%2){
            printf("%d\n", i);
            break;
        }
    }

}
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) solve();
    return 0;
}
