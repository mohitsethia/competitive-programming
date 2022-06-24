#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
void solve(){
    int n;
    cin >> n;
    set<int> s;
    long long prev;
    long long x;
    bool flag = true;
    while(n--){
        cin >> x;
        if(s.empty()){
            s.insert(x);
            prev = x;
            continue;
        }
        if(prev == x) continue;
        int small = min(x, prev);
        int big = max(x, prev);
        s.insert(x);
        if(*s.upper_bound(small) != big){
            flag = false;
        }
        prev = x;
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
