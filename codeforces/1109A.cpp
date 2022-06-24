#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int N = 3e6+10;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int res = 0;
    vector<int> cnt(N);
    cnt[1]++;
    int pref = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pref ^= x;
        int s = 2*pref + i % 2;
        res += cnt[s];
        cnt[s]++;
    }
    cout << res << "\n";
    return 0;
}
