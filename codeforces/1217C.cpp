#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') continue;
            int val = 0;
            int zeroes = 0;
            for(int j = i-1; j >= 0; j--){
                if(s[j] == '0') zeroes++;
                else break;
            }
            for(int j = i; j < n; j++){
                val = val*2 + (s[j]-'0');
                if(j-i+1+zeroes >= val) ans++;
                if(val > n) break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
