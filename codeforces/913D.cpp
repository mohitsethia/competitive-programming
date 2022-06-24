#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

struct prob{
    int a, t, idx;
    bool operator < (const prob &p) const{
        return t < p.t;
    }
};

int32_t main(){
    int n, T;
    cin >> n >> T;
    vector<prob> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].t;
        v[i].idx = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int l = 1, r = n;
    auto check = [&](int k){
        int sum = 0;
        int p = k;
        for(int i = 0; i < n && p; i++){
            if(v[i].a >= k){
                p--;
                sum += v[i].t;
            }
        }
        return !p && sum <= T;
    };
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << ans << "\n" << ans << "\n";
    int p = ans;
    for(int i = 0; i < n && p; i++){
        if(v[i].a >= ans){
            p--;
            cout << v[i].idx+1 << " ";
        }
    }
    cout << "\n";
    return 0;
}
