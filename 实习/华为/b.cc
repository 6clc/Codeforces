#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string s;
string tg;

bool check_num(string x){
    if(x[0] != '0') return false;
    if(!( x[1]=='x' || x[1] =='X')) return false;
    for(int i=2; i<x.size(); i++){
        if(x[i]>='0' && x[i] <='9') continue;
        if(x[i] >= 'a' && x[i] <= 'f') continue;
        if(x[i] >= 'A' && x[i] <= 'F') continue;
        return false;
    }
    return true;
}

void fail(){
    printf("%s\r\n", "FAIL");
}

string to_lower(string tmp){
    string y;
    for(auto ch:tmp) y.push_back(tolower(ch));
    return y;
}


int main(){
    cin >> s;

    tg.clear();

    int i;
    for(i=0; i<s.size(); i++){
        if(s[i] == ' ') break;
        tg.push_back(s[i]);
    }


    string st;
    st.clear();
    // string cur;
    // cout << tg << endl;
    map<string, string> ret;

    string dis[] = {"addr", "mask", "val"};

    cin >> s;

    bool f=false;
    bool has_ret = false;
    string dir;
    for(i = 0; i<s.size(); i++){
        if(s[i] == ']'){
            i+=1;
            if(f){
                  ret[dir]=st;
                  bool curf = true;
                  //for(auto kv:ret) cout << endl << kv.first << kv.second << endl;
                  for(int i=0; i<3; i++){
                      if(!check_num(ret[dis[i]])) {
                          curf=false;
                          break;
                      }
                  }
                  if(curf){
                      printf("%s %s %s\r\n", ret[dis[0]].c_str(), ret[dis[1]].c_str(), ret[dis[2]].c_str());
                  }else{
                      fail();
                  }
            }
          
            st.clear();
            ret.clear();
            f=false;

        }else if(s[i] == '['){
            // cout << st <<" " << tg<< endl;
            if(st == tg){
                f=true;
            }else{
                string x;
                string y;
                for(auto ch:st) x.push_back(tolower(ch));
                for(auto ch:tg) y.push_back(tolower(ch));
                // cout << x << y << endl;

                if(x == y){
                    fail();
                }
                f=false;
            }
            st.clear();
        }else if(s[i] == ','){
            ret[dir] = st;
            st.clear();
        }else if(s[i] == '='){
            dir = to_lower(st);
            //cout << "safa" << dir << endl;
            st.clear();
        }else{
            st.push_back(s[i]);
        }
    }

    // if(!has_ret){
    //     printf("%s\r\n", "FAIL");
    // }
    
    return 0;
}

//read read[mask=0xff,Addr=0x17,val=0x7],read_his[addr=0xff,mask=0xff,val=0x1],read[addr=0xf0,mask=0xff,val=0x80]