#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll cnt = 0;
        while(k > 3){
            cout << "1 ";
            n--;
            k--;
            cnt++;
        }
        if(n%3 == 0){
            cout << n/3 << " " << n/3 << " " << n/3;
        }
        else if((n/2+n/2) == n){
            if((n/2)%2 == 0){
                cout << n/2 << " " << n/4 << " " << n/4;
            }
            else{
                cout << n/2-1 << " " << n/2-1 << " 2";
            }
        }
        else{
            cout << n/2 << " " << n/2 << " 1";
        }
        cout << "\n";
    }
    return 0;
}
