#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll cnt2 = 0, cnt3 = 0;
        while(n%2 == 0){
            cnt2++;
            n /= 2;
        }
        while(n%3 == 0){
            cnt3++;
            n /= 3;
        }
        if(n == 1){
            if(cnt2 <= cnt3){
                ll ans = cnt2 + (cnt3-cnt2)*2;
                cout << ans << endl;
            }
            else{
                cout << "-1\n";
            }
        }
        else{
            cout << "-1\n";
        }
    }
    return 0;
}























/*
#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, c3 = 0, c2 = 0;
        cin >> n;
        while(n%3 == 0){
            c3++;
            n/=3;
        }
        while(n%2 == 0){
            c2++;
            n/=2;
        }
        if(n == 1 && c3 >= c2){
            cout << c3+(c3-c2) << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
    return 0;
}
*/
