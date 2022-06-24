#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1);
    for(int i = 1 ;i <= n; i++){
        cin >> a[i];
    }
    for(int j = 1 ;j <= n; j++){
        cin >> b[j];
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        mp[b[c[i]]]++;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(mp.find(a[i]) != mp.end()){
            cnt += mp[a[i]];
        }
    }
    cout << cnt << endl;
    return 0;
}
