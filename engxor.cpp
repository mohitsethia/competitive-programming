#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

#define ll long long int

ll b[100000000];

int oddeven(ll n){
    ll count = 0;
    while(n){
        count += n & 1;
        n >>= 1;
    }   
    return count;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        ll p, a[n], i, count1 = 0, count2 = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];
        }
        cin >> p;
        for(i = 0; i < n; i++){
            a[i] = a[i]^p;
            if(oddeven(a[i]) % 2 == 0){
                count1++;
            }
            else
                count2++;
        }
        cout << count1 << " " << count2 << endl;
    }
    return 0;
}
