#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

#define int long long

const int N = 3e5 + 10;

int l[N], r[N];

multiset<int> le, ri;

int32_t main(){
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        le.insert(l[i]);
        ri.insert(r[i]);
    }
    for(int i = 1; i <= n; i++){
        le.erase(le.find(l[i]));
        ri.erase(ri.find(r[i]));
        int res = max(0ll, *ri.begin() - *le.rbegin());
        ans = max(ans, res);
        le.insert(l[i]);
        ri.insert(r[i]);
    }
    cout << ans << "\n";
    return 0;
}
