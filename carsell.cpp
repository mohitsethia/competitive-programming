#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
int mycompare(ll a, ll b){
    return a > b;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll p[n], ans = 0;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        sort(p, p+n, mycompare);
        for(int i= 0; i < n; i++){
            if(p[i] - i >= 0){
                ans += p[i] - i;
            }
        }   
        cout << ans % 1000000007 << endl; 
    }
    return 0;
}
