#include<iostream>
#include<numeric>

using namespace std;

#define int long long

int32_t main(){
    int n, p;
    cin >> n >> p;
    for(int i = 1; i < 32; i++){
        if(__builtin_popcount(n-i*p) <= i && i <= n-i*p){
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
