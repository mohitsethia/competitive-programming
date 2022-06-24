#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long> suff(n);
    suff[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--){
        suff[i] = gcd(suff[i+1], a[i]);
    }
    long long ans = 0;
    for(int i = 0; i < n-1; i++){
        long long res = a[i]*suff[i+1]/suff[i];
        ans = gcd(res, ans);
    }
    cout << ans << endl;
    return 0;
}
