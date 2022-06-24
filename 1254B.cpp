#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> d(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        sum += d[i];
    }
    if(sum == 1){
        cout << "-1\n";
        return 0;
    }
    vector<int> divisors;
    for(int i = 2; i*i <= sum; i++){
        if(!(sum%i)){
            while(sum%i == 0){
                sum /= i;
            }
            divisors.emplace_back(i);
        }
    }
    if(sum > 1)
        divisors.push_back(sum);
    int ans = 1e18;
    for(int i = 0; i < (int)divisors.size(); i++){
        int curr = 0;
        int w = 0;
        for(int j = 0; j < n-1; j++){
            curr += d[j];
            int t = curr%divisors[i];
            w += min(t, divisors[i]-t);
        }
        ans = min(ans, w);
    }
    cout << ans << "\n";
    return 0;
}
