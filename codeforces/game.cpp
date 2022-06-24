#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n%2){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
    return 0;
}
