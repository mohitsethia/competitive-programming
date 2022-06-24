#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
void solve(){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i-1] == '1' && s[i] == '0'){
            cnt++;
        }
    }
    if(s[s.length()-1] == '1'){
        cnt++;
    }
    printf("%lld\n", cnt);
}
int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}
