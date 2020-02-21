#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    // std::cout << "Hello, World!" << std::endl;
    int n;
    cin >> n;
    vector<int> nums(n);

    int max_ix=0;
    for(int i=0; i<n; i++) {
        cin >> nums[i];
        if(nums[i] > nums[max_ix]) max_ix = i;
    }

    int lf = max_ix - 1;
    int rg = max_ix + 1;
    int max_val = nums[max_ix];

    while(lf>=0 && rg<n){
        if(nums[lf] > nums[rg]){
            if(nums[lf] >= max_val){cout << "NO" << endl; return 0;}
            max_val = nums[lf];
            lf -= 1;
        }else{
            if(nums[rg] >= max_val){cout << "NO" << endl; return 0;}
            max_val = nums[rg];
            rg += 1;
        }
    }
    while(lf>=0){
        if(nums[lf] >= max_val) {cout << "NO" << endl; return 0;}
        max_val = nums[lf];
        lf -= 1;
    }
    while(rg<n){
        if(nums[rg] >= max_val){cout << "NO" << endl; return 0;}
        max_val = nums[rg];
        rg += 1;
    }
    cout << "YES" << endl;
    return 0;
}
