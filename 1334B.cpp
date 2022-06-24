#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        long double sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += 1.0*a[i];
        }
        if(sum/(n*1.0) >= x){
            cout << n << "\n";
        }
        else{
            sort(a.begin(), a.end());
            int ans = n;
            for(int i = 0; i < n; i++){
                sum = sum - 1.0*a[i];
                ans--;
                if(sum/(ans*1.0) >= x) break;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
