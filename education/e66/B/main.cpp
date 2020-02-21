#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = ll(1ll<<32);
int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin >> n;
    stack<ll> st;
    st.push(1);
    ll ret = 0;
    while(n--){
        string s;
        cin >> s;

        if(s[0] == 'f'){
            ll x;
            cin >> x;
            st.push(min(st.top()*x, INF));
            // cout << x << " ";
        }else if(s[0] == 'a'){
            ret += st.top();
            if(ret >= INF){ cout << "OVERFLOW!!!" << endl; return 0;}
        }else if(s[0] == 'e'){
            st.pop();
        }
        // cout << s << endl;

    }
    //cout << ret << endl;
    if(ret >= INF) cout << "OVERFLOW!!!" << endl;
    else   cout << ret << endl;
    return 0;
}
