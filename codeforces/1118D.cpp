#include<iostream>
#include<algorithm>
#include<vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum < m){
        cout << "-1\n";
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    int low = 1, high = n;
    while(low < high){
        int mid = (low+high) >> 1;
        sum = 0;
        for(int i = 0; i < n; i++){
            sum += (a[i] - (i/mid));
            if(sum >= m) break;
        }
        if(sum >= m){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    cout << low << "\n";
    return 0;
}
