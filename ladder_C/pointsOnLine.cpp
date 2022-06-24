#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
long long a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, d;
    cin >> n >> d;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    long long res = 0;
    for(ll i = 0, j = 0; i < n; i++){
        while(a[j]-a[i] <= d && j < n) j++;
        res += (j-i-1)*(j-i-2)/2;
    }
    cout << res << endl;
    return 0;
}
