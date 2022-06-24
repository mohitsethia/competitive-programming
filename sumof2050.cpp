#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int sumOfDigits(int n){
    int sum = 0;
    while(n){
        int r = n%10;
        sum += r;
        n /= 10;
    }
    return sum;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n < 2050 || n%2050){
            cout << "-1" << endl;
        }
        else{
            cout << sumOfDigits(n/2050) << endl;
        }
    }
    return 0;
}
