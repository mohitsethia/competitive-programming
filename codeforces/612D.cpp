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
    int n, k;
    cin >> n >> k;
    map<int, vector<int> > mp;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        mp[l].push_back(1);
        mp[r+1].push_back(-1);
    }
    vector<int> v;
    int curr = 0;
    bool on = 0;
    for(auto &it: mp){
        for(auto &j: it.second){
            if(j == -1) curr--;
        }
        if(curr < k && on){
            v.push_back(it.first-1);
            on = false;
        }
        for(auto &j: it.second){
            if(j == 1) curr++;
        }
        if(curr >= k && !on){
            v.push_back(it.first);
            on = true;
        }
    }
    cout << v.size()/2 << "\n";
    for(int i = 0; i < v.size(); i += 2){
        cout << v[i] << " " << v[i+1] << "\n";
    }
    return 0;
}
