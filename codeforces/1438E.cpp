#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

#define int long long

using namespace std;

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n+1), pref(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    set<pair<int, int> > res;
    for(int i = 1; i <= n; i++){
        for(int j = i+2; j <= n; j++){
            if(pref[j-1]-pref[i] > 2*a[i]) break;
            if((a[i]^a[j]) == pref[j-1]-pref[i]) res.insert({i, j});
        }
    }
    for(int i = n; i >= 1; i--){
        for(int j = i-2; j >= 1; j--){
            if(pref[i-1]-pref[j] > 2*a[i]) break;
            if((a[i]^a[j]) == pref[i-1]-pref[j]) res.insert({j, i});
        }
    }
    cout << res.size() << "\n";
    return 0;
}
