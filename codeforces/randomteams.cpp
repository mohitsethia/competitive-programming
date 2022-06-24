#include<iostream>
#include<algorithm>
using namespace std;
#define int int64_t
int32_t main(){
    int n, m;
    cin >> n >> m;
    int mx = (n-m+1)*(n-m)/2;
    int sz = n/m;
    int rem = n%m;
    int mn = rem*(sz+1)*sz/2 + (m-rem)*sz*(sz-1)/2;
    cout << mn << " " << mx << endl;
    return 0;
}
