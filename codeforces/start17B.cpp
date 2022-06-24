#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;

#define int long long

vector<pair<int, int> > factorize(int n){
    if(n == 1) return {};
    vector<pair<int, int> > res;
    for(int i = 2; i*i <= n; i += (i&1)+1){
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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a;
        int b;
        cin >> b;
        a.push_back(b);
        int g = b;
        bool bad = false;
        for(int i = 1; i < n; i++){
            cin >> b;
            if(bad) continue;
            g = gcd(g, b);
            if(g != b){
                bad = true;
            }
            else{
                a.push_back(b);
            }
        }
        if(bad){
            cout << "-1\n";
            continue;
        }
        for(int i: a){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
