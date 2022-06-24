#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

signed main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        string s;
        cin >> x >> s;
        int i = 1;
        while((int)s.length() < x){
            int l = s.length();
            for(int j = 1; j < (s[i-1]-'0'); j++){
                s += s.substr(i, l-i);
            }
            i++;
        }
        int ans = (int)s.size();
        for( ; i <= x; i++){
            int temp = s[i-1] - '0';
            ans = (ans+(ans-i)*(temp-1)%MOD + MOD) % MOD;
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
