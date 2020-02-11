#include<bits/stdc++.h>
using namespace std;

int maxn = int(1e9+2);
unordered_map<string, vector<int>> mps;

    void recordTweet(string tweetName, int time) {
        if(mps.count(tweetName) == 0){
            mps[tweetName] = vector<int>(maxn, 0);
        }

        mps[tweetName][time] ++;
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        vector<int> ret;
        int t = 0;
        if(freq == "minute") t = 60; 
        else if(freq == "hour") t = 3600;
        else if(freq == "day") t = 43200;
       
        int st = startTime;
        while(st<=endTime){
            int cur = 0;
            for(int i=st; i<min(st+t, endTime+1); i++){
                cur += mps[tweetName][i];
            }
            st = min(st+t, endTime+1);
            // cout << st << "** " << endl;
            ret.push_back(cur);
        }

        return ret;
    }
int main(){
    recordTweet("tweet3", 0);
   recordTweet("tweet3", 60);
    recordTweet("tweet3", 10);                             // "tweet3" 发布推文的时间分别是 0, 10 和 60 。
   auto ret = getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
   for(auto x:ret) cout << x <<  " ";
   cout << endl;

   recordTweet("tweet3", 120); 
    ret = getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
   for(auto x:ret) cout << x <<  " ";
   cout << endl;

 ret = getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
   for(auto x:ret) cout << x <<  " ";
   cout << endl;
    return 0;
}