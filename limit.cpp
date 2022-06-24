#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a%b));
}
int main(){
    int n, m;
    cin >> n >> m;
    int a[n+1], b[m+1];
    for(int i = 0; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 0; i <= m; i++){
        cin >> b[i];
    }
    if(n > m){
        if((a[0] < 0 && b[0] < 0) || (a[0] > 0 && b[0] > 0)){
            cout << "Infinity\n";
            return 0;
        }
        cout << "-Infinity\n";
        return 0;
    }
    if(m > n){
        cout << "0/1\n";
        return 0;
    }
    bool a_neg = false, b_neg = false;
    if(a[0] < 0){
        a_neg = true;
        a[0] *= -1;
    }
    if(b[0] < 0){
        b_neg = true;
        b[0] *= -1;
    }
    int r = gcd(a[0], b[0]);
    if((a_neg && b_neg) || (!a_neg && !b_neg)){
        cout << a[0]/r << "/" << b[0]/r;
    }
    else{
        cout << "-" << a[0]/r << "/" << b[0]/r;
    }
    return 0;
}
