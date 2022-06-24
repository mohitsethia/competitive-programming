#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int cnt[26] = {0};
        for(int i = 0; i < (int)s.length(); i++){
            cnt[s[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += min(2, cnt[i]);
        }
        cout << ans/2 << "\n";
    }
    return 0;
}
