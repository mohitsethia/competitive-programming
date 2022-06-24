#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
typedef long long ll;
int dp[5001][5001];
vector<int> v1, v2;
long long calc(int i, int j){
    if(i == v1.size()){
        return 0;
    }
    if(j == v2.size()){
        return 2*1e18+1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = min(calc(i+1, j+1)+abs(v1[i]-v2[j]), calc(i, j+1));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    int c = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        if(a[i] == 1){
            c++;
        }
    }
    if(c == 0){
        cout << "0\n";
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            v1.push_back(i);
        }
        else{
            v2.push_back(i);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    memset(dp, -1, sizeof dp);
    cout << calc(0, 0) << endl;
    return 0;
}
