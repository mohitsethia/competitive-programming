#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b;
    cin >> a >> b;
    long long ans = b-a;
    long long n = 11;
    while(b/n > 0){
        ans -= ((b/n)-(a/n));
        n *= 10;
        ans -= ((b/n)-(a/n));
        n++;
    }
    cout << ans << "\n";
    return 0;
}
