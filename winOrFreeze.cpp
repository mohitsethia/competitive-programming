#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
vector<pair<int, int> > primeFactors(int n){
    vector<pair<int, int> > v;
    int x = 0;
    while(n%2 == 0){
        n /= 2;
        x++;
    }
    if(x){
        v.push_back({2, x});
    }
    for(int i = 3; i <= sqrt(n); i += 2){
        x = 0;
        while(n%i == 0){
             n /= i;
             x++;
        }
        if(x){
            v.push_back({i, x});
        }
        if(n == 1){
            break;
        }
    }
    if(n > 1){
        v.push_back({n, 1});
    }
    return v;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
        vector<pair<int, int> > v = primeFactors(n);
        if((v.size() == 1 && v[0].second == 1) || n == 1){
            cout << 1 << endl << 0;
        }
        else{
            if((v.size() == 1 && v[0].second == 2) || (v.size() == 2 && v[0].second == 1 && v[1].second == 1)){
                cout << 2 << endl;
            }
            else{
                cout << 1 << endl;
                if(v.size() == 1){
                    cout << pow(v[0].first, 2);
                }
                else{
                    cout << v[0].first*v[1].first << endl;
                }
            }
        }
    
    return 0;
}
