#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    int bmax = a[0].second;
    int ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i].second < bmax) ans++;
        else bmax = a[i].second;
    }
    cout << ans << endl;
    return 0;
}
