#include<iostream>
#include<algorithm>
using namespace std;
int countsetbits(int n){
    if(n == 0){
        return 0;
    }
    else
        return 1 + countsetbits(n & (n-1));
}
int main(){
    int t;
    cin >> t;
    int dp[10000] = {};
    while(t--){
        int l, r;  
        cin >> l >> r;
        int count = 0;
        for(int i = l; i <= r; i++){
            if(dp[i] == 0){
                dp[i] = countsetbits(i);
            }
            count += dp[i];
        }
        cout << count << endl;
    }
    return 0;
}
