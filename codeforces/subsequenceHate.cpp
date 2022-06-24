#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int suf0 = 0, suf1 = 0;
        for(int i = 0; i < s.length(); i++){
            suf0 += (s[i] == '0');
            suf1 += (s[i] == '1');
        }
        int pref0 = 0, pref1 = 0;
        int ans = min(suf0, suf1);
        for(auto &it: s){
            pref0 += (it == '0'), suf0 -= (it == '0');
            pref1 += (it == '1'), suf1 -= (it == '1');
            ans = min(ans, pref1+suf0);
            ans = min(ans, pref0+suf1);
        }
        cout << ans << endl;
    }
    return 0;
}
