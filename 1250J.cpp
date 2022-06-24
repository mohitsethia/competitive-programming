#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

bool check(int &mid, vector<int> a, int t){
    int start = 0;
    while(t){
        if(a[start] >= mid){
            t -= a[start]/mid;
            a[start] %= mid;
        }
        else{
            if(start +1 < (int)a.size() && a[start] + a[start+1] >= mid){
                t -= (a[start+1]+a[start])/mid;
                a[start+1] = (a[start+1]+a[start])%mid;
            }
            start++;
        }
        if(start >= (int)a.size()){
            break;
        }
    }
    return t <= 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        int ans = 0, left = 1, right = sum/k;
        while(left <= right){
            int mid = (left+right) >> 1;
            if(check(mid, a, k)){
                ans = mid;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        cout << ans*k << "\n";
    }
    return 0;
}
