#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
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
        int cnt[10] = {0};
        int n = (int)s.length();
        for(int i = 0; i < n; i++){
            cnt[s[i]-'0']++;
        }
        int ans = 0;
        for(int i = 0; i < 10; i++){
            ans = max(ans, cnt[i]);
        }
        ans = n - ans;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                bool f = true;
                int tt = 0;
                for(int k = 0; k < n; k++){
                    if(f == 0 && s[k]-'0' == i){
                        f = true;
                        tt++;
                    }
                    else if(f == 1 && s[k]-'0' == j){
                        f = false;
                        tt++;
                    }
                }
                if(tt&1) tt--;
                ans = min(ans, n-tt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}























/*
#include<iostream>
#include<algorithm>
#include<map>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        int freq[10] = {0};
        for(int i = 0; i < s.length(); i++){
            freq[s[i]-'0']++;
        }
        int mx = 0;
        for(int i = 0; i < 10; i++){
            mx = max(mx, freq[i]);
        }
        int ans = s.length()-mx;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                bool f = true;
                int tt = 0;
                for(int k = 0; k < s.length(); k++){
                    if(f && s[k] == '0' + i){
                        f = false;
                        tt++;
                    }
                    else if(!f && s[k] == '0'+j){
                        f = true;
                        tt++;
                    }
                }
                if(tt%2 == 1){
                    tt--;
                }
                ans = min(ans, n-tt);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
*/
