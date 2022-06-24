#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++){
        v[i] = v[i+1]-v[i];
    }

    sort(v.begin(), --v.end());

    int q;
    cin >> q;

    vector<int> pref(n);
    for(int i = 1; i < n; i++){
        pref[i] = pref[i-1] + v[i-1];
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        int range = r-l+1;
        int pos = lower_bound(v.begin(), --v.end(), range) - v.begin();

        cout << (n-pos)*range + pref[pos] << " ";
    }
    
    cout << "\n";
    return 0;
}
