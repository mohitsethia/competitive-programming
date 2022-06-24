#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int pref = 0;
    int ans = 0;
    mp[0]++;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref += a[i];
        if(mp.count(pref)){
            ans++;
            mp.clear();
            mp[0]++;
            pref = a[i];
        }
        mp[pref]++;
    }
    cout << ans << "\n";
    return 0;
}
