#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define int long long

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1){
        cout << a[0]+k << "\n";
        return 0;
    }
    sort(a.begin(), a.end());
    int small = 1, big = 2e9;
    while(small < big){
        int mid = (small+big+1)/2;
        int moves = 0;
        bool bad = false;
        for(int i = n/2; i < n; i++){
            if(mid-a[i] > 0) moves += mid-a[i];
            if(moves > k){
                bad = true;
                break;
            }
        }
        if(!bad && moves <= k){
            small = mid;
        }
        else{
            big = mid-1;
        }
    }
    cout << small << "\n";
    return 0;
}
