#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<numeric>
#include<iomanip>
#include<cmath>
using namespace std;
using ll = long long;
void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    string res = "";
    for(int i = 0; i < k; i++){
        res += s[i%n];
    }
    for(int i = 0; i < n; i++){
        string p = "";
        string temp = s.substr(0, i+1);
        for(int j = 0; j < k; j++){
            p += temp[j%(i+1)];
        }
        res = min(res, p);
    }
    cout << res << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
