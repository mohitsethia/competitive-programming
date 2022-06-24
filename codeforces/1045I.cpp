#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define int long long

bool counter(vector<int> &a, vector<int> &b){
    int o = 0;
    for(int i = 0; i < 26; i++){
        if((a[i] + b[i])%2) o++;
    }
    return o <= 1;
}

int32_t main(){
    int n;
    cin >> n;
    int cnt = 0;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int mask = 0;
        vector<int> c(26);
        for(char ch: s){
            c[ch-'a']++;
        }
        for(int j = 0; j < 26; j++){
            if(c[j]%2) mask |= (1 << j);
        }
        mp[mask]++;
    }
    for(auto &it: mp){
        if(it.first == 0){
            cnt += (it.second * (it.second-1))/2;
            continue;
        }
        int mask = it.first;
        for(int j = 0; j < 26; j++){
            if((mask >> j)&1){
                int currMask = mask & (~(1<<j));
                if(currMask < mask){
                    if(mp.find(currMask) != mp.end()){
                        cnt += it.second * mp[currMask];
                    }
                }
            }
        }
        cnt += (it.second * (it.second-1))/2;
    }
    cout << cnt << "\n";
    return 0;
}
