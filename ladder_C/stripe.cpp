#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
#define endl '\n'
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum%2){
        cout << 0 << endl;
    }
    else{
        sum /= 2;
        ll cnt = 0;
        ll sum2 = 0;
        for(int i = 0; i < n-1; i++){
            sum2 += a[i];
            if(sum2 == sum){
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
