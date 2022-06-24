#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, flag = 0;
        cin >> n;
        ll a[n];
        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ll x = i+a[i];
            x = ((x%n)+n)%n;
            if(s.find(x) != s.end()){
                flag = 1;
            }
            s.insert(x);
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
