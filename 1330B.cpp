#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    map<int, int> mp;
    set<int> s1, s2;
    bool ok = true;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        mp[a[i]]++;
        s1.insert(a[i]);
        if(mp[a[i]] > 2){
            ok = false;
        }
    }
    if(mp[1] < 2 || !ok){
        cout << "0\n";
        return;
    }
    vector<pair<int, int> > ans;
    for(int i = 0; i < n; i++){
        if(mp[a[i]] == 2){
            s2.insert(a[i]);
            mp[a[i]]--;
            continue;
        }
        if(s2.size()){
            int m1 = *s1.rbegin();
            int m2 = *s2.rbegin();
            if(m1 == s1.size() && m2 == s2.size() && m2 == i && m1 == n-i){
                ans.push_back({i, n-i});
            }
        }
        if(mp[a[i]] == 1){
            s2.insert(a[i]);
            s1.erase(a[i]);
        }
    }
    cout << (int) ans.size() << "\n";
    for(auto it: ans){
        cout << it.first << " " << it.second << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
