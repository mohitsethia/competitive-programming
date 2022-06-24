#include<iostream>
#include<algorithm>
#include<climits>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;

int P, K;

int mod_pow(int a, int p){
    if(p == 0) return 1;
    return a*mod_pow(a, p-1)%MOD;
}

int32_t main(){
    cin >> P >> K;
    if(K == 0){
        cout << mod_pow(P, P-1) << "\n";
    }
    else if(K == 1){
        cout << mod_pow(P, P) << "\n";
    }
    else{
        int c = K, it = 1;
        for(; c != 1 ; it++){
            c = c*K % P;
        }
        cout << mod_pow(P, (P-1)/it) << "\n";
    }
    return 0;
}
