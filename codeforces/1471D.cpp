#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long

using namespace std;

const int N = 1e6 + 2;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    vector<int> p(N, 1);
    for(int i = 1; i < N; i++){
        int tmp = i;
        for(int j = 2; j*j <= tmp; j++){
            if(tmp%j == 0){
                int cnt = 0;
                while(tmp%j == 0){
                    tmp /= j;
                    cnt++;
                }
                if(cnt&1) p[i] *= j;
            }
        }
        if(tmp > 1) p[i] *= tmp;
    }
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[p[a[i]]]++;
        }
        int ans = 0, ans1 = 0;
        for(auto it: mp){
            if(it.first == 1){
                ans = max(ans, it.second);
                ans1 = max(ans1, it.second);
            }
            else{
                ans = max(ans, it.second);
                if(it.second%2 == 0){
                    ans1 += it.second;
                }
            }
        }
        ans1 = max(ans1, ans);
        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            if(x) cout << ans1 << "\n";
            else cout << ans << "\n";
        }
    }
    return 0;
}
