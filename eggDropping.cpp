//binary search way

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
ll binomialCoefficient(int mid, int eggs, int floors){
    ll sum = 0, term = 1;
    for(ll i = 0; i < eggs; i++){
        term *= mid-i;
        term /= (i+1);
        sum += term;
        if(sum > floors) return sum;
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int eggs, floors;
    cin >> eggs >> floors;
    int l = 1, r = floors, ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(binomialCoefficient(mid, eggs, floors) >= 1ll*floors){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;
}

/*
//dp-way

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int eggs, floors;
    cin >> eggs >> floors;
    vector<vector<int> > dp(eggs+1, vector<int>(floors+1));
    for(int i = 0; i <= eggs; i++){
        dp[i][1] = 1;
    }
    for(int i = 0; i <= floors; i++){
        dp[1][i] = i;
    }
    for(int i = 2; i <= eggs; i++){
        for(int j = 2; j <= floors; j++){
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; x++){
                dp[i][j] = min(dp[i][j], 1+max(dp[i-1][x-1], dp[i][j-x]));
            }
        }
    }
    cout << dp[eggs][floors] << "\n";
    return 0;
}
*/
