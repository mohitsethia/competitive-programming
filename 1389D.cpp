#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>

#define endl "\n"
using namespace std;
using ll = long long;

void solve(){
    ll n, k;
    cin >> n >> k;
    ll l1, l2, r1, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    //exact overlap
    if(l1 == l2 && r1 == r2){
        ll o = r1-l1;
        if(o*n >= k){
            cout << "0\n";
        }
        else{
            ll ex = 2*(k-o*n);
            cout << ex << endl;
        }
        return;
    }
    if(l1 > l2){
        swap(l1, l2);
        swap(r1, r2);
    }
    //partial overlap
    if(r1 >= l2 && r1 <= r2){
        ll o = r2-l1;
        o *= n;
        ll ex = 0;
        if(o < k) ex += 2*(k-o);
        ll curr = r1-l2;
        curr *= n;
        if(curr >= k){
            cout << "0\n";
        }
        else{
            k = min(o, k);
            ex += k-curr;
            cout << ex << endl;
        }
        return;
    }
    //completely in
    if(l2 >= l1 && r1 >= r2){
        ll o = r1-l1;
        o *= n;
        ll ex = 0;
        if(o < k) ex += 2*(k-o);
        ll curr = r2-l2;
        curr *= n;
        if(curr >= k){
            cout << "0\n";
        }
        else{
            k = min(o, k);
            ex += k-curr;
            cout << ex << endl;
        }
        return;
    }
    //away
    ll ex = 0;
    ll ans = INT_MAX;
    ll o = r2-l1;
    ll dis = l2-r1;
    for(int i = 0; i < n; i++){
        ex += dis;
        if(o >= k){
            ex += k;
            ans = min(ans, ex);
            break;
        }
        ex += o;
        k -= o;
        ans = min(ans, ex + 2*k);
    }
    cout << ans << endl;
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
