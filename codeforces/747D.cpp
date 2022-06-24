#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    int ans = 0, neg = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] >= 0) a[i] = 0;
        else a[i] = -1;
        neg += a[i] < 0;
    }
    if(neg > k){
        cout << "-1\n";
        return 0;
    }
    int check = 0, cntSum = 0;
    vector<pair<int, int> > v;
    for(int i = 1; i <= n; i++){
        if(a[i] != a[i-1]){
            ans++;
        }
        if(a[i] >= 0) cntSum++;
        else{
            k--;
            if(cntSum > 0 && check >= 1)
                v.push_back({cntSum, check});
            check++;
            cntSum = 0;
        }
    }
    if(cntSum > 0 && check >= 1) v.push_back({cntSum, check});
    sort(v.begin(), v.end());
    int storeLast = -1;
    for(auto it: v){
        if(it.second == check){
            storeLast = it.first;
            continue;
        }
        if(it.first <= k){
            k -= it.first;
            ans -= 2;
        }
    }
    if(storeLast != -1 && storeLast <= k) ans--;
    cout << ans << "\n";
    return 0;
}
