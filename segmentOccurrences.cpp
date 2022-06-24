#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int> > k;
    if(n < m){
        for(int i = 0 ;i < q; i++){
            int l, r;
            cin >> l >> r;
            cout << 0 << endl;
        }
        return 0;
    }
    string v = s.substr(0, m);
    if(v == t) k.push_back({1, m});
    int i = 1, j = m;
    while(j < n){
        v.erase(v.begin());
        v = v + s[j];
        if(v == t) k.push_back({i+1, j+1});
        i++, j++;
    }
 //   for(auto it: k){
   //     cout << it.first << " " << it.second << endl;
    //}
    for(int i = 0; i < q; i++){
        int ans = 0;
        int l, r;
        cin >> l >> r;
        for(auto it: k){
            if(it.first >= l && it.second <= r){
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
