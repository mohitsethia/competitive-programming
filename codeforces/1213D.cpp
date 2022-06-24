#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    unordered_map<int, vector<int> > mp;
    for(int i = 0; i < n; i++){
        int x, cnt = 0;
        cin >> x;
        while(x){
            mp[x].push_back(cnt);
            x /= 2;
            cnt++;
        }
    }
    int res = INT_MAX;
    for(auto it: mp){
        if(it.second.size() < k) continue;
        sort(it.second.begin(), it.second.end());
        int sum = 0;
        for(int i = 0; i < min(k, (int)it.second.size()); i++){
            sum += it.second[i];
        }
        res = min(res, sum);
    }
    cout << res << "\n";
    return 0;
}
