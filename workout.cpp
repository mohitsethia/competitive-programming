#include<iostream>
using namespace std;
#define int long long
const int N = 1e5+5;
int n, k;
int a[N];
bool check(int d){
    int reqadditional = 0;
    for(int i = 1; i + 1 <= n; i++){
        reqadditional += (a[i+1] - a[i] - 1)/d;
    }
    if(reqadditional <= k){
        return 1;
    }
    return 0; 
}
int binsearch(int lo, int hi){
    while(lo < hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid+1; 
        }
    }
    return lo;
}
int32_t main(){
    int t;
    cin >> t;
    int tc = 0;
    while(t--){
        tc++;
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int ans = binsearch(1, 1e9);
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
