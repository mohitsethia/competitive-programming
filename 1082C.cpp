#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;
    map<int, vector<int> > mp;
    bool isPos = false;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        if(y > 0) isPos = true;
    }
    if(!isPos){
        cout << "0\n";
    }
    else{
        vector<int> best(n+1);
        for(int i = 1; i <= m; i++) if(mp[i].size()) sort(mp[i].rbegin(), mp[i].rend());
        for(int i = 1; i <= m; i++){
            int curr = 0;
            for(int j = 0; j < (int)mp[i].size(); j++){
                curr += mp[i][j];
                if(curr < 0) break;
                best[j+1] += curr;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, best[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}
