#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#define endl '\n'
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
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << 3*n << endl;
        for(int i = 0; i < n; i+=2){
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "1 " << i+1 << " " << i+2 << endl;
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "2 " << i+1 << " " << i+2 << endl;
            cout << "1 " << i+1 << " " << i+2 << endl;
        }
    }
    return 0;
}
