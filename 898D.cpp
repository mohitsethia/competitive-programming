#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

#define int long long

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0, ans = 0;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        while(!dq.empty() && (a[i]-dq.front()) >= m){
            cnt--;
            dq.pop_front();
        }
        cnt++;
        if(cnt >= k){
            cnt--;
            ans++;
        }
        else{
            dq.push_back(a[i]);
        }
    }
    cout << ans << "\n";
    return 0;
}
