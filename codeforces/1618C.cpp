#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int g1 = 0, g2 = 0;;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i%2) g1 = gcd(g1, a[i]);
            else g2 = gcd(g2, a[i]);
        }
        for(int i = 0; i < n; i += 2){
            if(a[i] % g1 == 0){
                g1 = -1;
                break;
            }
        }
        for(int i = 1; i < n; i += 2){
            if(a[i] % g2 == 0){
                g2 = -1;
                break;
            }
        }
        if(g1 > 0){
            cout << g1 << "\n";
        }
        else if(g2 > 0){
            cout << g2 << "\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}
