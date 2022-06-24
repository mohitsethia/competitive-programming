#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a < b){
            cout << "1\n";
            continue;
        }
        else if(a == b){
            cout << "2\n";
            continue;
        }
        ll cnt = INT_MAX;
        for(ll i = 0; i <= 20; i++){
            if(b == 1 && i == 0) continue;
            ll tmp = i, x = a, y = b+i;
            while(x > y){
                x /= y;
                tmp++;
            }
            if(x == y){
                tmp += 2;
            }
            else if(x > 0){
                tmp++;
            }
            cnt = min(cnt, tmp);
        }
        cout << cnt << "\n";
    }
    return 0;
}
