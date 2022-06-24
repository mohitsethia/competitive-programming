#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    pair<int, int> best{INT_MAX, INT_MAX};
    for(int b = 0; b <= n; b++){
        int a = (n-b*7)/4;
        if(a < 0 || b*7 + a*4 != n) continue;
        best = min(best, {a+b, b});
    }
    if(best.first == INT_MAX){
        cout << "-1" << endl;
        return 0;
    }
    int a = best.first-best.second;
    int b = best.second;
    for(int i = 0; i < a; i++){
        cout << "4";
    }
    for(int j = 0; j < b; j++){
        cout << "7";
    }
    cout << endl;
    return 0;
}
