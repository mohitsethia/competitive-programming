#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define ll long long
void primeFactors(ll n, pair<ll, ll> *arr, ll count){
    ll x = 0;
    while(n%2 == 0){
        x++;
        n /= 2;
    }
    if(x > 0)
        arr[count].first = 2;
    for(ll i = 3; i <= sqrt(n); i += 2){
        x = 0;
        while(n%i == 0){
            x++;
            n /= i;
        }
        if(x > 0){
            if(arr[count].first == -1){
                arr[count].first = i;
                cout << i << " ";
                continue;
            }    
            arr[count].second = i;
            cout << i << endl;
            break;
        }
    }
}
int main(){
    ll n;
    cin >> n;
    ll a[n];
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    pair<ll, ll> arr[n];
    for(ll i = 0; i < n; i++){
        arr[i].first = arr[i].second = -1;
        primeFactors(a[i], arr, i);
        if(arr[i].second != -1)
            cout << arr[i].first << " ";
        else
            cout << "-1 ";
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i].second << " ";
    }
}
