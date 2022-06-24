#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int main(){
    vector<vector<int> > mp(26);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
        mp[s[i]-'a'].push_back(i);
    }
    int q;
    cin >> q;
    while(q--){
        string p;
        cin >> p;
        int ans = 0;
        vector<int> cnt(26);
        for(int i = 0; i < (int)p.length(); i++){
            cnt[p[i]-'a']++;
        }
        for(int i = 0; i < 26; i++){
            int sz = cnt[i];
            if(sz == 0) continue;
            int idx = mp[i][sz-1];
            ans = max(ans, idx);
        }
        cout << ans+1 << endl;
    }
    return 0;
}
