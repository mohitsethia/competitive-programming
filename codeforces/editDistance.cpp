#pragma GCC optimize("O2")
#pragma GCC target("sse4")
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
/*
vector<vector<int> > dp(5001, vector<int>(5001, -1));
int calc(int i, int j, string& a, string& b){
    if(i == 0){
        return j;
    }
    if(j == 0){
        return i;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    return dp[i][j] = min(calc(i-1, j-1, a, b) + ((a[i-1] == b[j-1]) ? 0 : 1), min(calc(i-1, j, a, b) + 1, calc(i, j-1, a, b) +1 ));
}
*/

void printEdits(vector<vector<int> >& dp, string& a, string& b){
    int i = a.length();
    int j = b.length();
    while(1){
        if(i == 0 || j == 0){
            break;
        }
        if(a[i-1] == b[j-1]){
            i--, j--;
        }
        else if(dp[i][j] == dp[i-1][j-1] + 1){
            cout << "Replacing " << b[j-1] << " in string 2 to " << a[i-1] << " in string 1\n";
            i--, j--;
        }
        else if(dp[i][j] == dp[i-1][j] + 1){
            cout << "Delete in string 1 " << a[i-1] << endl;
            i--;
        }
        else if(dp[i][j] == dp[i][j-1] + 1){
            cout << "Add in string 1 " << b[j-1] << endl;
            j--;
        }
        else{
            cout << "Some errors\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    //cout << calc(n, m, a, b) << endl;
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    for(int i = 0; i <= n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= m ;j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
            }
        }
    }
    cout << "Number of operations = ";
    cout << dp[n][m] << endl;
    printEdits(dp, a, b);
    return 0;
}
