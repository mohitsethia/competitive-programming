#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> mp(k+1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mp[x]++;
    }
    vector<int> emp;
    for(int i = 1; i <= k; i++){
        if(mp[i])
            emp.emplace_back(mp[i]);
    }
    sort(emp.begin(), emp.end());
    int p = emp.size();
    if(p == 1){
        cout << emp[0] << "\n";
        return 0;
    }
    int ans = 1e18;
    int mx = emp[p-1]+emp[p-2];
    for(int i = emp[p-1]; i <= mx; i++){
        int l = 0, r = p-1, cnt = 0;
        while(l < r){
            cnt++;
            if(emp[l]+emp[r] <= i){
                l++, r--;
            }
            else{
                r--;
            }
        }
        if(l == r){
            cnt++;
        }
        ans = min(ans, cnt*i);
        if(cnt == (p+1)/2) break;
    }
    cout << ans << "\n";
    return 0;
}
