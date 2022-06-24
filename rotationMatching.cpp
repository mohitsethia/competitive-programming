#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1), pos(n+1);
    map<int, int> mp;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int curr = pos[b[i]]-i;
        if(curr < 0){
            curr += n;
        }
        mp[curr]++;
    }
    for(auto &it: mp){
        ans = max(ans, it.second);
    }
    cout << ans << endl;
    return 0;
}
