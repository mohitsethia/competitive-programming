#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<numeric>
using namespace std;
using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> even, odd;
        int x;
        for(int i = 0; i < n; i++){
            cin >> x;
            if(x%2 == 0){
                even.push_back(x);
            }
            else{
                odd.push_back(x);
            }
        }
        ll ans = 0;
        for(int i = 0; i < (int)odd.size(); i++){
            even.push_back(odd[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(gcd(even[i], 2*even[j]) > 1){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
