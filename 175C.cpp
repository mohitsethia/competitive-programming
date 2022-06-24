#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    pair<int, int> v[n];
    for(int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v, v+n);
    int sum = 0, cnt = 0;
    int t;
    cin >> t;
    for(int f = 1, i = 0; f <= t+1 && i < n; f++){
        int p = 1e18;
        if(f <= t) cin >> p;
        while(i < n && cnt < p){
            int k = min(v[i].second, p-cnt);
            sum += v[i].first*k*f;
            cnt += k;
            if((v[i].second -= k) == 0) i++;
        }
    }
    cout << sum << "\n";
    return 0;
}
