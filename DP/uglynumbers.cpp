//Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included.

//Given a number n, the task is to find n’th Ugly number.


#include<iostream>
#include<algorithm>
using namespace std;
int dp[10005] = {0};
void ugly(){
    int next_2 = 2;
    int next_3 = 3;
    int next_5 = 5;
    dp[0] = 1;
    int i2 = 0, i3 = 0, i5 = 0;
    for(int i = 1; i < 10005; i++){
        dp[i] = min(next_2, min(next_3, next_5));
        if(dp[i] == next_2){
            i2++;
            next_2 = dp[i2]*2;
        }
        if(dp[i] == next_3){
            i3++;
            next_3 = dp[i3]*3;
        }
        if(dp[i] == next_5){
            i5++;
            next_5 *= dp[i5]*5;
        }
    }
}
int main(){
    int t;
    cin >> t;
    ugly();
    while(t--){
        int n;
        cin >> n;
        cout << dp[n-1] << endl;
    }
    return 0;
}
