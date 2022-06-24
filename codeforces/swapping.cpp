#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define int long long
const int N = 2e5 + 1;
int n;
vector<int> a(N);
vector<int> b(N);
struct AB{
    int A;
    int B;
    AB(){}
    AB(int _A, int _B): A(_A), B(_B){}
};
int best = 0;
void solve(){
    vector<AB> A_high, B_high;
    for(int i = 0; i < n; i++){
        if(a[i] > b[i]){
            A_high.emplace_back(a[i], b[i]);
        }
        else{
            B_high.emplace_back(a[i], b[i]);
        }
    }
    sort(A_high.begin(), A_high.end(), [&](const AB &x, const AB &y){
        return x.B < y.B;
    });
    sort(B_high.begin(), B_high.end(), [&](const AB &x, const AB &y){
        return x.A < y.A;
    });
    int mx = 0, idx = 0;
    for(auto &it: A_high){
        while(idx < (int)B_high.size() && B_high[idx].A <= it.B){
            mx = max(mx, B_high[idx++].B);
        }
        best = max(best, min(mx, it.A) - it.B);
    }
}

int32_t main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += abs(a[i]-b[i]);
    }
    solve();
    swap(a, b);
    solve();
    cout << ans - 2*best << "\n";
    return 0;
}
