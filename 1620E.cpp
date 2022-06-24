#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

const int N = 5e5+1;

int32_t main(){
    int q;
    cin >> q;
    vector<int> type(q), x(q), y(q);
    for(int i = 0; i < q; i++) {
        cin >> type[i] >> x[i];
        if(type[i] == 2){
            cin >> y[i];
        }
    }
    vector<int> ans;
    vector<int> f(N);
    iota(f.begin(), f.end(), 0);
    for(int i = q-1; i >= 0; i--) {
        if(type[i] == 1) {
            ans.push_back(f[x[i]]);
        }
        else {
            f[x[i]] = f[y[i]];
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
