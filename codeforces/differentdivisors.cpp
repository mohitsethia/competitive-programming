#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
#define int long long
bool isPrime(int n){
    if(n <= 3){
        return true;
    }
    if(n % 2 == 0 || n % 3 == 0){
        return false;
    }
    for(int i = 5; i*i <= n; i += 6){
        if(n % i == 0 || n % (i+2) == 0){
            return false;
        }
    }
    return true;
}
int nextPrime(int n){
    for(int i = n+1; i >= n; i++){
        if(isPrime(i)){
            return i;
        }
    }
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int d, ans = 1;
        cin >> d;
        if(isPrime(1+d)){
            ans = 1+d;
        }
        else{
            ans = nextPrime(1+d);
        }
        if(isPrime(ans+d)){
            ans *= (ans+d);
        }
        else{
            ans *= nextPrime(ans+d);
        }
        cout << ans << endl;
    }
    return 0;
}
