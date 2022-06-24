#include<iostream>
#include<cstring>
using namespace std;
#define MAX_SIZE 10000007
#define ll long long int
ll arr[10000007] = {0};
ll cum[10000007] = {0};
void prime(){
    for(ll i = 3; i < MAX_SIZE; i+=2){
        arr[i] = 1;
    }
    for(ll i = 3; i < MAX_SIZE; i+=2){
        if(arr[i] == 1){
            for(ll j = i*i; j < MAX_SIZE; j+=i){
                arr[j] = 0;
            }
        }
    }
    arr[2] = 1;
    arr[0] = arr[1] = 0;
}
int32_t main(){
    ll t;
    cin >> t;
//    cout << t;
//    ll arr[MAX_SIZE] = {0};
//    memset(arr, 0, sizeof(arr));
    prime();
//    ll cum[10000007] = {0};
    for(ll i = 1; i < 10000007; i++){
        cum[i] = cum[i-1] + arr[i];
    }
    while(t--){
        ll l, r;
        cin >> l >> r;
        if(l >= 1){
            cout << cum[r]-cum[l-1] << endl;
        }
        else{
            cout << cum[r] << endl;
        }
    }
    return 0;
}

