#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    for(auto it: mp){
        a.emplace_back(it.second);
    }
    sort(a.begin(), a.end());
    int sz = a.size();
    int ans = 0;
    for(int i = a[sz-1]; i >= 0; i--){
        int val = i;
        int cnt = 0;
        int pos = sz-1;
        while(pos >= 0 && a[pos] >= val && val > 0){
            cnt += val;
            pos--;
            if(val&1) break;
            val = val>>1;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
    return 0;
}
