#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll = long long;
const ll N = 1e6+1;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll cnt[N] = {0};
    for(ll i = a; i <= b; i++){
        cnt[i+b]++;
        cnt[i+c+1]--;
    }
    for(ll i = 0; i < N; i++){
        cnt[i+1] += cnt[i];
    }
    ll triangles = 0;
    for(ll i = 0; i < N; i++){
        if(i > c){
            triangles += cnt[i] * (min(i-1, d) - c+1);
        }
    }
    cout << triangles << "\n";
    return 0;
}
