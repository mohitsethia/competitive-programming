#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int l = 1, r = n+1;
    while(r-l > 1){
        int mid = (l+r)/2;
        b = vector<int>(n);
        for(int i = 0; i < n; i++){
            if(a[i] >= mid){
                b[i] = 1;
            }
            else{
                b[i] = -1;
            }
            if(i){
                b[i] += b[i-1];
            }
        }
        int mx = b[k-1];
        int mn = 0;
        for(int i = k; i < n; i++){
            mn = min(mn, b[i-k]);
            mx = max(mx, b[i]-mn);
        }
        if(mx > 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l << "\n";
    return  0;
}
