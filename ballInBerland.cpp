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
    int t;
    cin >> t;
    while(t--){
        int A, B, k;
        cin >> A >> B >> k;
        vector<int> cntb(A+1), cntg(B+1), a(k), b(k);
        for(int i = 0; i < k; i++){
            cin >> a[i];
            cntb[a[i]]++;
        }
        for(int i = 0; i < k; i++){
            cin >> b[i];
            cntg[b[i]]++;
        }
        ll ans = 0;
        for(int i = 0; i < k; i++){
            ans += k - (cntb[a[i]] + cntg[b[i]]) + 1;
        }
        cout << ans/2 << endl;
    }
    return 0;
}
