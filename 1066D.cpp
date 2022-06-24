#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    int rem = 0;
    for(int i = 0; i < n; i++){
        if(rem < a[i]){
            if(m == 0){
                cout << i << "\n";
                return 0;
            }
            else{
                m--;
                rem = k-a[i];
            }
        }
        else{
            rem -= a[i];
        }
    }

    cout << n << "\n";

    return 0;
}
