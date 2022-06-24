#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

vector<pair<int, int> > factorize(int n){
    vector<pair<int, int> > res;
    if(n == 1) return res;
    for(int i = 2; i*i <= n; i++){
        int cnt = 0;
        while(n%i == 0){
            n /= i;
            cnt++;
        }
        if(cnt)
            res.push_back({i, cnt});
    }
    if(n > 1){
        res.push_back({n, 1});
    }
    return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n%m){
            cout << n << "\n";
        }
        else{
            vector<pair<int, int> > f = factorize(m);
            int res = 1;
            for(auto it: f){
                int cnt = 0;
                int temp = n;
                while(temp % it.first == 0){
                    temp /= it.first;
                    cnt++;
                }
                int req = min(it.second-1, cnt);
                for(int i = 1; i <= req; i++){
                    temp *= it.first;
                }
                res = max(res, temp);
            }
            cout << res << "\n";
        }
    }
    return 0;
}
