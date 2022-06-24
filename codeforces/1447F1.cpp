#include<iostream>
#include<algorithm>
#include<vector>

#define int long long

using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> cnt(101);
    int mx = 0, p = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
        if(mx < cnt[a[i]]){
            mx = cnt[a[i]];
            p = a[i];
        }
    }
    for(int i = 1; i <= 100; i++){
        if(cnt[i] == mx && i != p){
            cout << n << "\n";
            return 0;
        }
    }
    vector<int> f;
    int res = 0;
    for(int i = 1; i <= 100; i++){
        f = vector<int> (2*n+5, -1);
        f[n] = 0;
        int s = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == p) s--;
            else if(a[j] == i) s++;
            if(f[s+n] != -1) res = max(res, j-f[s+n]);
            else f[s+n] = j;
        }
    }
    cout << res << "\n";
    return 0;
}
