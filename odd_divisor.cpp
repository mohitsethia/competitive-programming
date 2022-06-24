#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        while(n%2 == 0){
            n /= 2;
        }
        if(n > 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
