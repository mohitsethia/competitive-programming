#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int comb(int x){
    if(x%2) return ((x+1)/2)*x;
    return (x/2)*(x+1);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n*n <= k){
            cout << 2*n-1 << "\n";
            continue;
        }
        int w = comb(n);
        if(w <= k){
            int want = k-w;
            int l = 0, r = n;
            while(r-l > 1){
                int mid = (l+r)/2;
                if(comb(n-1)-comb(mid) < want) r = mid;
                else l = mid;
            }
            cout << n + (n-1-r)+1 << "\n";
        }
        else{
            int l = 0, r = n;
            while(r-l > 1){
                int mid = (l+r)/2;
                if(comb(mid) < k) l = mid;
                else r = mid;
            }
            cout << l+1 << "\n";
        }
    }
    return 0;
}
