#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
#define ll long long int
vector<pair<int, int> > primeFactors(ll n){
    vector<pair<int, int> > v;
    if(n <= 1){
        return v;
    }
    int x = 0;
    if(n % 2 == 0){
        while(n % 2 == 0){
            n = n/2;
            x++;
        }
        v.push_back(make_pair(2, x));
    }
    for(int i = 3; i <= sqrt(n); i += 2){
        x = 0;
        if(n % i == 0){
            while(n % i == 0){
                n /= i;
                x++;
            }
            v.push_back(make_pair(i, x));
        }
    }
    if(n > 1){
        v.push_back(make_pair(n, 1));
    }
    return v;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x, k, pf, f = 1;
        cin >> x >> k;
        vector<pair<int, int> > v = primeFactors(x);
        for(auto i : v){
            f += (i.second);
        }
        if(f >=  k){
            cout << "1" << endl;
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}
