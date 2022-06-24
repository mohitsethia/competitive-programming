#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<set>
#include<map>
#define int long long
using namespace std;
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(2*n);
        bool p = false;
        for(int i = 0; i < 2*n; i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i = 1; i < 2*n; i++){
            vector<pair<int, int> > ans;
            ans.push_back({v[0], v[i]});
            int mx = v[0];
            map<int, int> mp;
            for(int j = 1; j < 2*n; j++){
                if(i != j){
                    mp[v[j]]++;
                }
            }
            while(mp.size()){
                auto it = mp.end();
                --it;
                int ff = it->first;
                if(it->second == 1){
                    mp.erase(it);
                }
                else{
                    it->second--;
                }
//                cout << "In map " << mx << endl;
                auto itt = mp.find(mx - it->first);
                if(itt == mp.end()){
                    break;
                }
                ans.push_back({ff, itt->first});
                if(itt->second == 1){
                    mp.erase(itt);
                }
                else{
                    itt->second--;
                }
                mx = ff;
            }
            if(ans.size() == n){
                p = true;
                cout << "YES\n";
                cout << v[0] + v[i] << endl;
                for(auto pp : ans){
                    cout << pp.first << " " << pp.second << endl;
                }
                break;
            }
        }
        if(!p){
            cout << "NO\n";
        }
    }
    return 0;
}
