#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string a = s, b = t;
    vector<pair<int, int> > v;
    for(int i = 0; i < n-1; i++){
        if(a[i] != b[i]){
            int id = -1;
            for(int j = i+1; j < n; j++){
                if(a[i] == b[j]){
                    id = j;
                    break;
                }
            }
            if(id == -1){
                for(int j = i+1; j < n; j++){
                    if(a[i] == a[j]){
                        id = j;
                        break;
                    }
                }
                if(id == -1) break;
                v.push_back({id, i});
                swap(a[id], b[i]);
            }
            else{
                v.push_back({i, i});
                swap(a[i], b[i]);
                v.push_back({i, id});
                swap(a[i], b[id]);
            }
        }
    }
    if(a != b){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        cout << v.size() << "\n";
        for(auto it: v){
            cout << it.first+1 << " " << it.second+1 << "\n";
        }
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
