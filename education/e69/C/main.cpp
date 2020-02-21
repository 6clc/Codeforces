#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
   //  std::cout << "Hello, World!" << std::endl;
   int n;
   int k;
   cin >> n >> k;

   vector<int> nums(n);
   vector<int> dis;
   for(int i=0; i<n; i++){
       cin >> nums[i];
       if(i) dis.push_back(nums[i] - nums[i-1]);
   }

   sort(begin(dis), end(dis));

   int ret = 0;
   for(int i=0; i<dis.size()-k+1; i++) ret += dis[i];
   cout << ret << endl;
   return 0;
}
