#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll low = 1, high = 1e9+10;
    ll ans = INT_MAX;
    while(low <= high){
        ll mid = (low+high)/2;
        ll r = mid*(mid+1)/2;
        if(r >= n){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    return 0;
}
