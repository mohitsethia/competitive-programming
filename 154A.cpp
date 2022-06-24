#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

#define int long long

int32_t main(){
    string s;
    int k;
    cin >> s >> k;
    map<char, char> mp;
    for(int i = 1; i <= k; i++){
        char c1, c2;
        cin >> c1 >> c2;
        mp[c1] = c2;
        mp[c2] = c1;
    }
    int retain = 0;
    for(int i = 0; i < (int)s.length(); i++){
        map<char, int> cnt;
        while(i < (int)s.length() && (s[i+1] == s[i] || s[i+1] == mp[s[i]])){
            cnt[s[i]]++;
            i++;
        }
        cnt[s[i]]++;
        int mx = 0;
        for(auto it: cnt){
            mx = max(mx, it.second);
        }
        retain += mx;
    }
    cout << s.size() - retain << "\n";
    return 0;
}
