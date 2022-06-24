#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define pb push_back
vector<vector<bool> > dp(100005, vector<bool>(100005, false));
void display(vector<int>& a){
    for(int& x: a){
        cout << x << " ";
    }
    cout << endl;
}
void printSubseq(vector<int>& a, int i, int sum, vector<int>& p){
    if(i == 0 && sum != 0 && dp[i][sum]){
        p.pb(a[i]);
        display(p);
        return;
    }
    if(i == 0 && sum == 0){
        display(p);
        return;
    }
    if(dp[i-1][sum]){
        vector<int> b = p;
        printSubseq(a, i-1, sum, b);
    }
    if(sum >= a[i] && dp[i-1][sum-a[i]]){
        p.push_back(a[i]);
        printSubseq(a, i-1, sum-a[i], p);
    }
    return;
}
void subsetSum(vector<int>& a, int& n, int& target){
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    if(a[0] <= target) dp[0][a[0]] = true;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= target; j++){
            dp[i][j] = dp[i-1][j];
            if(dp[i-1][j] != true && a[i] <= j) dp[i][j] = dp[i-1][j-a[i]];
        }
    }
    if(!dp[n-1][target]){
        cout << "Not Possible\n";
        return;
    }
    vector<int> p;
    printSubseq(a, n-1, target, p);
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& x: a){
        cin >> x;
    }
    int target;
    cin >> target;
    subsetSum(a, n, target);
    return 0;
}
