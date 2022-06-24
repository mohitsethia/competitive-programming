#include<iostream>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
int N = 1000005;
bool isPrime(int n){
    if(n%2 == 0){
        return false;
    }
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin >> t;
    map<int, int> mp;
    mp[2]++;
    vector<int> dp(N, 0);
    int cnt = 0;
    for(int i = 3; i <= N; i+=2){
        if(isPrime(i)){
            mp[i]++;
            if(mp.count(i-2)){
                cnt++;
                dp[i] = cnt;
            }
        }
    }
    while(t--){
        int n;
        cin >> n;
        if(n < 5){
            cout << 0 << endl;
        }
        for(int i = n; i >= 0; i--){
            if(dp[i]){
                cout << dp[i] << endl;
                break;
            }
        }
    }
    return 0;
}
