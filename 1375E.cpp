#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<pair<int, int> > v(n);
    for(int i = 0; i < n; i++){
        v[i].second = i;
        cin >> v[i].first;
    }
    sort(v.begin(), v.end());
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[v[i].second] = i;
    }
    vector<pair<int, int> > res;

    for(int i = 0; i < n; i++){
        int idx = 0;
        for(int j = 0; j < n; j++){
            if(a[j] == i) idx = j;
        }
        for(int j = n-1; j >= idx; j--){
            if(a[j] < a[idx]){
                res.push_back({idx, j});
                swap(a[idx], a[j]);
            }
        }
    }

    cout << res.size() << "\n";
    for(pair<int, int> i: res){
        cout << i.first +1 << " " << i.second +1 << "\n";
    }
    return 0;
}
