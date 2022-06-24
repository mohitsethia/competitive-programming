#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

#define int long long
using namespace std;


int32_t main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int g = 0;
    sort(a.begin(), a.end());
    for(int i = 1; i < n; i++){
        g = gcd(g, a[i]-a[0]);
    }
    while(m--){
        int x;
        cin >> x;
        cout << gcd(g, a[0]+x) << " ";
    }
    return 0;
}
