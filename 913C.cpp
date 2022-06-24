#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

const int inf = 2e18;

int32_t main(){
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        a[i] = min(a[i], 2*a[i-1]);
    }
    int sum = 0;
    int best = inf;
    for(int i = n-1; i >= 0; i--){
        int temp = (1 << i);
        if(l >= temp){
            sum += a[i] * (l/temp);
            l %= temp;
        }
        if(l){
            best = min(best, sum + a[i]);
        }
    }
    best = min(best, sum);
    cout << best << "\n";
    return 0;
}
