#include<stdio.h>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define MAX 1000005
#define MOD 1000000007
#define ll long long int

ll getPower(ll a){
    while(a % 2 == 0)
        a /= 2;
    return a;
}


int main() {

    int t;
    cin >> t;

    while(t--) {

        ll a, b;

        cin >> a >> b;

        if(a > b) swap(a, b);

        if(getPower(a) != getPower(b)) {
            cout << "-1\n";
            continue;
        }
        ll ans = 0;

        b/=a;

        while(b>=8) {
            b/=8;
            ans++;
        }
        if(b > 1) ans++;

        cout << ans << "\n";
    }

    return 0;
   
}

