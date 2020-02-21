#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> nums;
    int a = 0;
    int b = 0;
    for(int i=0; i<n; i++){
        string tmp;
        cin >> tmp;
        for(int j=0; j<tmp.size(); j++){
            if(tmp[j] == '0'){
                a += 1;
            }else{
                b += 1;
            }
        }
        nums.push_back(tmp.size());
    }

    for(int i=0; i<nums.size(); i++){
        if(nums[i]&1){
            if(a&1){
                a -= 1;
                nums[i] -= 1;
            }else if(b&1){
                b -= 1;
                nums[i] -= 1;
            }
        }
    }

    if((a&1) && (b&1)) cout << nums.size() - 1 << endl;
    else if((a&1) || (b&1)) cout << nums.size() - 1 << endl;
    else cout << nums.size() << endl;
   //  else cout << << endl;
}


int main() {
    // std::cout << "Hello, World!" << std::endl;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
