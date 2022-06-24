#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    ll res = 0;
    while(b != 0){
        res += a/b;
        a %= b;
        swap(a, b);
    }
    cout << res << endl;
    return 0;
}
