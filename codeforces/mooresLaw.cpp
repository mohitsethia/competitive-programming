#include<iostream>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
using ll = long long;
double power(double base, ll exp){
    double res = 1.0;
    while(exp){
        if(exp&1){
            res = res*base;
        }
        exp /= 2;
        base *= base;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, t;
    cin >> n >> t;
    double base = 1.000000011;
    cout << fixed << setprecision(6) << n*power(base, t) << endl;
    return 0;
}
