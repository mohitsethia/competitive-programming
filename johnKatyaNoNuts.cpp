#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, m;
    cin >> n >> m;
    if(n >= m){
        if(m == 0){
            cout << 2*n+1 << "\n";
        }
        else{
            cout << "0\n";
        }
    }
    else{
        if(2*n > m){
            cout << "0\n";
        }
        else{
            cout << m+1 << "\n";
        }
    }
    return 0;
}
