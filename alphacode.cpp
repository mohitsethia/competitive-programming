#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    string s;
    cin >> s;
    while(s[0] != '0'){
        int dp[5005] = {0};
        dp[0] = 1;
        int i = 1;
        while(i < s.length()){
            int sum = (s[i-1]-'0')*10;
            int k = s[i]-'0';
            if(k > 0){
                dp[i] += dp[i-1];
            }
            sum += k;
            if(sum > 9 && sum <= 26){
                dp[i] += dp[(i-2) < 0 ? 0 : (i-2)];
            }
            i++;
        }
        cout << dp[s.length()-1] << endl;
        cin >> s;
    }
    return 0;
}


/*

#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    string s;
    cin >> s;
    int dp[5003];
    while(s[0] != '0'){
        memset(dp, 0, sizeof dp);
        int i = 1;
        dp[0] = 1;
        int l = s.length();
        while(i < l){
            int sum = (s[i-1]-'0')*10;
            int k = s[i] - '0';
            sum += k;
//            cout << i << " Initial " << dp[i] << " " << dp[i-1] << endl;
            if(k > 0){
                dp[i] += dp[i-1];
            }
//            cout << dp[i] << " dp at i " << endl;
            if(sum > 9 && sum <= 26){
                dp[i] += dp[(i-2) < 0 ? 0 : (i-2)];
            }
//            cout << i << " i " << dp[i] << " " << dp[i-2] << endl;
            i++;
        }
        cout << dp[l-1] << endl;
        cin >> s;
    }
    return 0;
}

*/
