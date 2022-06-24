#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>

using namespace std;
#define int long long

int phi(int n){
    int result = n;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            result -= result/i;
        }
    }
    if(n > 1){
        result -= result/n;
    }
    return result;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int g = gcd(n, m);
        m /= g;
        cout << phi(m) << "\n";
    }
    return 0;
}
