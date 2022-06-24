#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
#include<map>
#include<list>
#include<set>
#include<queue>
#include<stack>
#include<unordered_set>
#include<cstdlib>
#include<string>
using namespace std;
#define mod 1000003
#define int int64_t
int power(int n, int p){
    int ans = 1;
    while(p > 0){
        if(p&1){
            ans *= n;
            ans %= mod;
        }
        p /= 2;
        n *= n;
        n %= mod;
    }
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    map<char, string> mp;
    mp['>'] = "1000";
    mp['<'] = "1001";
    mp['+'] = "1010";
    mp['-'] = "1011";
    mp['.'] = "1100";
    mp[','] = "1101";
    mp['['] = "1110";
    mp[']'] = "1111";
    string s;
    cin >> s;
    string intm = "";
    for(char i : s){
        intm += mp[i];
    }
    int ans = 0;
    for(int i = intm.size()-1; i >= 0; i--){
        if(intm[i] == '1'){
            int kk = power(2,intm.size()-1-i);
            kk %= mod;
            ans += kk;
            ans %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}









