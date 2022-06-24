#include<iostream>
#include<algorithm>

using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            if(a[i] == a[i-1]) continue;
            int res = 0, ptr = i;
            while(ptr <= n){
                ptr = lower_bound(a.begin()+ptr+1, a.end(), 2*a[ptr]-a[i]) - a.begin();
                res++;
            }
            ans = max(ans, res);
        }
        cout << n-ans << "\n";
    }
    return 0;
}
