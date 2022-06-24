#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<set>

using namespace std;

#define int long long

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(3), b(3);
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];
    vector<pair<int, int> > shouldnot;
    set<pair<int, int> > win;
    win.insert({0ll, 1ll});
    win.insert({1ll, 2ll});
    win.insert({2ll, 0ll});
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                shouldnot.emplace_back(make_pair(i, j));
            }
            else{
                auto it = make_pair(i, j);
                if(win.find(it) != win.end()){
                    continue;
                }
                else{
                    shouldnot.emplace_back(it);
                }
            }
        }
    }
    sort(shouldnot.begin(), shouldnot.end());
    int ans = a[0]+a[1]+a[2];
    do{
        vector<int> a1 = a, b1 = b;
        for(int i = 0; i < (int)shouldnot.size(); i++){
            int cnt = min(a1[shouldnot[i].first], b1[shouldnot[i].second]);
            a1[shouldnot[i].first] -= cnt;
            b1[shouldnot[i].second] -= cnt;
        }
        int curr = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
        ans = min(ans, curr);
    }while(next_permutation(shouldnot.begin(), shouldnot.end()));
    int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    cout << ans << " " << mx << "\n";
    return 0;
}
