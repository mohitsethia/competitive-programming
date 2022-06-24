#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

#define int long long
using namespace std;

/*
const int N = 1e5+1;
vector<pair<int, int> > factors[N];

void precompute(int k){
    vector<int> done(N);
    for(int i = 2; i < N; i++){
        if(!done[i]){
            factors[i].emplace_back(i, 1);
            for(int j = 2*i; j < N; j += i){
                done[j] = 1;
                int cnt = 0, x = j;
                while(x%i == 0){
                    cnt++, x /= i;
                }
                if(cnt % k != 0){
                    factors[j].emplace_back(i, cnt%k);
                }
            }
        }
    }
}
*/

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    // precompute(k);
    map<vector<pair<int, int> >, int> mp;
    int res = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        vector<pair<int, int> > v;
        for(int j = 2; j*j <= x; j++){
            int cnt = 0;
            while(x%j == 0){
                cnt++;
                x /= j;
            }
            cnt %= k;
            if(cnt) v.emplace_back(j, cnt);
        }
        if(x > 1) v.emplace_back(x, 1);
        vector<pair<int, int> > need;
        for(auto c: v){
            need.emplace_back(c.first, k-c.second);
        }
        res += mp[need];
        mp[v]++;
    }
    cout << res << "\n";
    return 0;
}
