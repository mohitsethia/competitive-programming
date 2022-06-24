#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll teams = 0, p = n;
        for(int i = n-1; i >= 0; i--){
            if((p-i)*a[i] >= x){
                teams++, p = i;
            }
        }
        cout << teams << endl;
    }
    return 0;
}
