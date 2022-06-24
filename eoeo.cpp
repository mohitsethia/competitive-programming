#include<iostream>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<vector>
#include<cstring>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if(n%2 == 0){
            while(n%2 == 0){
                n /= 2;
            }
            n /= 2;
            cout << n << endl;
        }
        else{
            cout << n/2 << endl;
        }
    }
    return 0;
}
