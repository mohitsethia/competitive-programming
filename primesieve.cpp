#include<iostream>
using namespace std;
#define ll long long int
void primesieve(int *p, int n){
    for(int i = 3; i <= n; i += 2){
        p[i] = 1;
    }
    for(ll i = 3; i <= n; i += 2){
        for(int j = i * i; j <= n; j += i){
            p[j] = 0;
        }
    }
    p[2] = 1;
    p[0] = p[1] = 0;
}
int main(){
    int n;
    cin >> n;
    int p[n];
    primesieve(p, n);
    for(int i = 2; i <= n; i++){
        if(p[i] == 1){
            cout << i << " ";
        }
    }
    return 0;
}
