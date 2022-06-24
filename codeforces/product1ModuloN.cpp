#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a%b));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> ans;
    long long product = 1;
    for(int i = 1; i < n; i++){
        if(gcd(i, n) == 1){
            ans.emplace_back(i);
            (product *= i) %= n;
        }
    }
    int k = product%n;
    bool greaterModulo = false;
    if(k != 1){
        greaterModulo = true;
    }
    else k = 0;
    if(greaterModulo){
        cout << ((int)ans.size() - 1) << "\n";
    }
    else{
        cout << (int)ans.size() << "\n";
    }
    for(int i = 0; i < (int)ans.size(); i++){
        if(ans[i] == k) continue;
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
