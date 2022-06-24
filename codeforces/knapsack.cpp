/*
//0-N knapsack problem1
#include<iostream>
using namespace std;
int main(){
    int n, s;
    cin >> n >> s;
    int wt[n], val[n];
    for(int i = 0; i < n; i++){
        cin >> wt[i];
    }
    for(int i = 0; i < n; i++){
        cin >> val[i];
    }
    int dp[s+1];
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= s; i++){
        for(int j = 0; j < n; j++){
            if(wt[j] <= i){
                dp[i] = max(dp[i], dp[i-wt[j]]+val[j]);
            }
        }
    }
    cout << dp[s] << endl;
    return 0;
}
*/
//0-1 knapsack problem
#include<iostream>
using namespace std;
int knapsack(int W, int wt[], int val[], int n, int **dp){
	if(n < 0){
		return 0;
	}
	if(dp[n][W] != -1){
		return dp[n][W];
	}
	if(wt[n] > W){
		return dp[n][W] = knapsack(W, wt, val, n-1, dp);
	}
	else{
		return dp[n][W] = max((val[n]+knapsack(W-wt[n], wt, val, n-1, dp)), knapsack(W, wt, val, n-1, dp));
	}
}
int main(){
	int n, s;
	cin >> n >> s;
	int wt[n], p[n];
	for(int i  = 0; i < n; i++){
		cin >> wt[i];
//        cout << wt[i] << " ";
	}
	for(int i = 0; i < n; i++){	
		cin >> p[i];
//        cout << p[i] << " ";
	}
	int **dp;
	dp = new int*[n];
	for(int i = 0; i < n; i++){
		dp[i] = new int[s+1];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < s+1; j++){
			dp[i][j] = -1;
		}
	}
	cout << knapsack(s, wt, p, n-1, dp) << endl;
	return 0;
}

