#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<string> s;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        s.push_back(x);
    }
    int ans = 1;
    for(int i = 0; i < m; i++){
        int cnt[26] = {0};
        for(int j = 0; j < n; j++){
            cnt[s[j][i]-'A']++;
        }
        int counter = 0;
        for(int j = 0; j < 26; j++){
            if(cnt[j]) counter++;
        }
        counter %= mod;
        ans *= counter;
        ans %= mod;
    }
    cout << ans << endl;
}
