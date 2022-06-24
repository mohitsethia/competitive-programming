#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

#define int long long

using namespace std;

void solve(){
    int n, T, a, b;
    cin >> n >> T >> a >> b;
    vector<pair<int, int> > task(n);
    int num[2] = {};
    for(int i = 0; i < n; i++){
        cin >> task[i].second;
        num[task[i].second]++;
    }
    for(int i = 0; i < n; i++){
        cin >> task[i].first;
    }
    task.push_back({T+1, 0});
    sort(task.begin(), task.end());
    int ans = 0;
    int need[2] = {};
    for(int i = 0; i <= n; i++){
        int t = task[i].first-1;
        int left = t - (a*need[0] + b*need[1]);
        if(left >= 0){
            int score = need[0] + need[1];
            int doa = min(left/a, num[0]-need[0]);
            left -= doa*a;
            int dob = min(left/b, num[1]-need[1]);
            score += doa + dob;
            ans = max(ans, score);
        }
        need[task[i].second]++;
    }
    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
