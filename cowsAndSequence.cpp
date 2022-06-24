#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll len = 0;
    ll sum = 0;
    vector<ll> arr(n+3), arr1(n+3);
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        if(t == 1){
            ll a, x;
            cin >> a >> x;
            sum += min(len+1, a)*x;
            arr1[min(len+1, a)-1] += x;
        }
        else if(t == 2){
            ll k;
            cin >> k;
            arr[len+1] = k;
            len++;
            sum += k;
        }
        else{
            arr1[len-1] += arr1[len];
            sum -= (arr1[len] + arr[len]);
            arr[len] = 0;
            arr1[len] = 0;
            len--;
        }
        cout << fixed << setprecision(6) << (double)sum/(1.0*(len+1)) << endl;
    }
    return 0;
}
