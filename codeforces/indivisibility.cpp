#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    //numbers divisible by 2, 3, 5 and 7
    ll m = n - (n/2) - (n/3) - (n/5) - (n/7);

    //numbers counted twice
    m += n/(2*3);
    m += n/(2*5);
    m += n/(2*7);
    m += n/(3*5);
    m += n/(3*7);
    m += n/(5*7);
    
    //numbers subtracted twice
    m -= n/(2*3*5);
    m -= n/(2*3*7);
    m -= n/(2*5*7);
    m -= n/(3*5*7);

    //number counted twice
    m += n/(2*3*5*7);

    cout << m << endl;
    return 0;
}
