#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
int rod_cut(vector<int>& price, int n){
    vector<int> val(n+1);
    int i , j;
    for(i = 1; i <= n; i++){
        int max_val = INT_MIN;
        for(j = 0; j < i; j++){
            max_val = max(max_val, price[j] + val[i-j-1]);
        }
        val[i] = max_val;
    }
    return val[n];
}
int main(){
    int n;
    cin >> n;
    vector<int> price(n), length(n);
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    cout << rod_cut(price, n) << endl;
    return 0;
}
