#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;
#define int long long

int digi(int x){
    int sum = 0;
    while(x){
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int32_t main(){
    int n;
    cin >> n;
    int s = sqrt(n);
    int ans = -1;
    for(int i = max(0ll, s-100); i <= s; i++){
        if(i < 1){
            continue;
        }
        if(n%i == 0 && i+digi(i) == n/i){
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}
