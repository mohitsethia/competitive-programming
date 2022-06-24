#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
#define int long long
#define mk make_pair
void solve(){
    int n, b;
    cin >> n >> b;
    vector<pair<int, int> > prime;
    for(int i = 2; i <= sqrt(b); i++){
        if(b%i == 0){
            int count = 0;
            while(b%i == 0){
                b /= i;
                count++;
            }
            prime.push_back(mk(i, count));
        }
    }
    if(b != 1){
        prime.push_back(mk(b, 1));
    }
    int ans = 1e18;
    for(auto i : prime){
        int p = i.first, count = 0, temp = n;
 //       cout << i.first << " " << i.second << endl;
        while(temp > 0){
            count += temp/p;
            temp /= p;
        }
        ans = min(ans, count/i.second);
    }
    cout << ans << endl;
    return;
}
int32_t main(){
    solve();    
    return 0;
}
