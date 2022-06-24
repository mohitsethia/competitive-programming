#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
using ll = long long;
ll fastModulo(ll base, ll exp){
    ll res = 1;
    while(exp){
        if(exp&1){
            res *= base;
        }
        base *= base;
        exp /= 2;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, b, c;
    cin >> a >> b >> c;
    bool first = false, second = false;
    if(a < 0){
        first = true;
        a = -a;
    }
    if(b < 0){
        second = true;
        b = -b;
    }
    long double ans1 = (long double)a * (long double)(log((long double)(c)));

    long double ans2 = (long double)b * (long double)(log((long double)(c)));
    if(first && c%2){
        ans1 *= (long double)-1;
    }
    if(second && c%2){
        ans2 *= (long double)-1;
    }
    if(ans1 < ans2){
        cout << '<' << endl;
    }
    else if(ans1 > ans2){
        cout << '>' << endl;
    }
    else{
        cout << "=" << endl;
    }
    return 0;
}
