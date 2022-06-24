#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    sort(arr+1, arr+n+1);
    ll mx = -1, mc = 0, sum = 0, l = 1;
    for(ll i = 1; i <= n; i++){
        sum += arr[i];
        while(arr[i] * (i-l+1) - sum > k){
            sum -= arr[l++];
        }
        if(i-l+1 > mc){
            mc = i-l+1;
            mx = arr[i];
        }
    }
    cout << mc << " " << mx << endl;
    return 0;
}
