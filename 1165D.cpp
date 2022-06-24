#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

#define int long long

vector<pair<int, int> > factorize(int n){
    vector<pair<int, int> > res;
    for(int i = 2; i*i <= n; i += (i&1)+i){
        if(n%i == 0){
            int cnt = 0;
            while(n%i == 0){
                n /= i;
                cnt++;
            }
            res.push_back({i, cnt});
        }
    }
    if(n > 1){
        res.push_back({n, 1});
    }
    return res;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> d(n);
        for(int i = 0; i < n; i++) cin >> d[i];
        sort(d.begin(), d.end());
        set<int> factor;
        int poss = d[0]*d[n-1];
        for(int i = 2; i * i <= poss; i++){
            if(poss%i == 0){
                factor.insert(i);
                factor.insert(poss/i);
            }
        }
        if((int)factor.size() != n){
            cout << "-1\n";
            continue;
        }
        int ans = poss;
        for(int i = 0; i < n; i++){
            if(factor.count(d[i]) == 0){
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
