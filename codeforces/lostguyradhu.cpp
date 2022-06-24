#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n, q;
        cin >> n >> q;
        ll a[n], b[q], max = 0, k = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < q; i++){
            cin >> b[i];
            for(int j = k; j < b[i]; j++){
                if(max < a[j]){
                    max = a[j];
                }
                k = j;
            }
            cout << max << endl;
        }
        
    }
    return 0;
}
