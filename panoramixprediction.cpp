#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){
    if(n%2 == 0){
        return false;
    }
    for(int i = 3; i <= sqrt(n); i+=2){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}   
int main(){
    int n, m;
    cin >> n >> m;
    if(!isprime(m)){
        cout << "NO" << endl;
        return 0;
    }
    for(int i = n+1; i < m; i++){
        if(isprime(i)){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
