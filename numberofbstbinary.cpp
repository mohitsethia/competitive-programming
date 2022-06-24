#include<iostream>
#include<vector>
using namespace std;
int fact(int x){
    if(x == 0 || x == 1){
        return 1;
    }
    return x*fact(x-1);
}
int nodes(int n, int dp[]){
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 0; j < i; j++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
int catalan(int n){
    if(n <= 1){
        return 1;
    }
    int res = 0;
    for(int i = 0; i < n; i++){
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}
int main(){
//    int n, r, dp[100];
    int c, n, a;
        cout << "Enter 1 to find number of bst & 2 to number of binary trees, and the number of nodes: ";
        cin >> c >> n;
        a = ((fact(2*n))/(fact(n)))/(fact(n+1));
        if(c == 1){
            cout << a << endl;
        }
        if(c == 2){
            int b = (fact(n))*a;
            cout << b << endl; 
        }   
/*
    cin >> n;
    cout << nodes(n, dp) << endl;
*/
    return 0;
}
