#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            ans += i*100 + j;
        }
    }
    cout << ans << endl;
    return 0;
}
