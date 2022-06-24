#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, k;
    cin >> n >> k;
    int j = 1;
    vector<int> a(n+2);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]) a[j++] = a[i];
    }
    n = j;
    vector<int> kk(k+2);
    kk[a[0]]++;
    for(int i = 1; i+1 < n; i++){
        kk[a[i]] += a[i-1] != a[i+1] ? 1 : 2;
    }
    kk[a[n-1]]++;
    int p = 1;
    for(int i = 2; i <= k; i++){
        if(kk[p] < kk[i]) p = i;
    }
    cout << p << "\n";
    return 0;
}
