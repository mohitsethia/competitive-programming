#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, s;
    cin >> n >> s;
    if(2*n <= s){
        cout << "YES\n";
        for(int i = 0; i < n-1; i++){
            cout << "2 ";
            s -= 2;
        }
        cout << s << "\n1\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
