#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll i = 1, j = n;
    while(i < j){
        cout << i << " " << j << " ";
        i++, j--;
    }
    if(i == j && n%2){
        cout << i << endl;
    }
    return 0;
}
