#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    ll x;
    for(int i = 1; i <= n; i++){
        cin >> x;
        a[i] = a[i-1];
        if(x < 0){
            a[i]++;
        }
    }
    ll odd_negative = 1;
    ll even_negative = 0;
    ll neg_ans = 0;
    for(int i = 1; i <= n; i++){
        if(a[i]%2){
            neg_ans += odd_negative;
            even_negative++;
        }
        else{
            neg_ans += even_negative;
            odd_negative++;
        }
    }
    ll total_pairs = 1ll*n*(n+1)/2;
    cout << neg_ans << " " << total_pairs-neg_ans << endl;
    return 0;
}
