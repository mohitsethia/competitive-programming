#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int last = a[0]+2;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int curr = -1;
        for(int j = 1; j >= -1; j--){
            if(a[i]+j > 0 && a[i]+j < last){
                curr = a[i]+j;
                break;
            }
        }
        if(curr == -1) continue;
        ++ans;
        last = curr;
    }
    cout << ans << "\n";
    return 0;
}
