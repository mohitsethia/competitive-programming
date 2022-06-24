#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define int long long
void solve(){
    int n, totalHours, timeLeft;
    cin >> n >> totalHours >> timeLeft;
    bool canBeDone = false;
    for(int i = 0; i < n; i++){
        int timeZone;
        cin >> timeZone;
        if(timeZone + timeLeft >= totalHours){
            canBeDone = true;
        }
    }
    if(canBeDone){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}
int32_t main(){
    solve();
    return 0;
}
