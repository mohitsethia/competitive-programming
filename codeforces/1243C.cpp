#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            while(n%i == 0){
                n /= i;
            }
            cout << (n == 1 ? i : 1) << "\n";
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}
