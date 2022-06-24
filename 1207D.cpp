#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

const int MOD = 998'244'353;
const int N = 3e5 + 2;
int f[N];

void factorial(){
    f[0] = f[1] = 1;
    for(int i = 2; i < N; i++){
        f[i] = (f[i-1]*i) % MOD;
    }
}

void calc(vector<pair<int, int> > &a, int &ans){
    int n = a.size();
    sort(a.begin(), a.end());
    int d = 1;
    int l = 0;
    while(l < n){
        int r = l+1;
        while(r < n && a[l].first == a[r].first) r++;
        d = (d*f[r-l]) % MOD;
        l = r;
    }
    ans = (ans + MOD-d) % MOD;
}

void swapper(vector<pair<int , int> > &a){
    int n = a.size();
    for(int i = 0; i < n; i++){
        swap(a[i].first, a[i].second);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    factorial();
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int ans = f[n];
    calc(a, ans);
    swapper(a);
    calc(a, ans);
    swapper(a);
    sort(a.begin(), a.end());
    int l = 0;
    int d = 1;
    while(l < n){
        int r = l+1;
        while(r < n && a[l].first == a[r].first) r++;
        map<int, int> mp;
        for(int i = l; i < r; i++){
            mp[a[i].second]++;
        }
        for(auto p: mp){
            d = (d*f[p.second]) % MOD;
        }
        l = r;
    }
    for(int i = 1; i < n; i++){
        if(a[i-1].second > a[i].second) d = 0;
    }
    ans = (ans + d) % MOD;
    cout << ans << "\n";
    return 0;
}
