#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

int32_t main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> up(n+2), right(n+2);
    for(int i = 0; i < n; i++){
        up[i+1] = up[i];
        right[i+1] = right[i];
        if(s[i] == 'U') up[i+1]++;
        else if(s[i] == 'D') up[i+1]--;
        else if(s[i] == 'L') right[i+1]--;
        else right[i+1]++;
    }

    int x, y;
    cin >> y >> x;
    if(up[n] == x && right[n] == y){
        cout << "0\n";
        return 0;
    }

    auto check = [&](int L){
        for(int i = 1; i+L-1 <= n; i++){
            int remup = up[i-1] + up[n] - up[i+L-1];
            int remr = right[i-1] + right[n] - right[i+L-1];
            int reqdu = abs(x-remup);
            int reqdr = abs(y-remr);
            if(reqdu + reqdr <= L && (L - (reqdu+reqdr))%2 == 0) return 1;
        }
        return 0;
    };

    auto binSearch = [&](int lo, int hi){
        while(lo < hi){
            int mid = (lo+hi)>>1;
            if(check(mid)){
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        return lo;
    };

    int ans = binSearch(1, n);
    if(check(ans)){
        cout << ans << "\n";
    }
    else{
        cout << "-1\n";
    }
    return 0;
}
