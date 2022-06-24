#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>

using namespace std;

#define int long long

void solve(){
    int c;
    cin >> c;
    int temp = c;
    int numberOfBits = 0;
    while(temp){
        temp /= 2;
        numberOfBits++;
    }
    int a = pow(2, numberOfBits-1)-1;
    int b = a^c;
    cout << a*b << "\n";
}

int32_t main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
