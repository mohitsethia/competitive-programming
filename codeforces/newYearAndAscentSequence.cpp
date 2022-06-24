#include<iostream>
#include<algorithm>
#include<cstdio>
#include<climits>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int> > p;
    for(int g = 1; g <= n; g++){
        int m;
        cin >> m;
        int mx = INT_MIN, mn = INT_MAX;
        vector<int> v(m);
        for(int i = 0; i < m; i++){
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        if(is_sorted(v.begin(), v.end())){
            p.emplace_back(make_pair(v[0], v.back()));
        }
    }
    sort(p.begin(), p.end());
    long long ans = 1ll*n*n;
    for(int i = 0; i < (int)p.size(); i++){
        ans -= (p.end() - lower_bound(p.begin(), p.end(), pair<int, int>(p[i].second, -1)));
    }
    cout << ans << endl;
    return 0;
}
