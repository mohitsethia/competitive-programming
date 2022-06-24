#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long

int32_t main(){
    int n, d;
    cin >> n >> d;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        a[i].second *= -1;
    }
    int res = 0;
    sort(a.begin(), a.end());
    int i = 0, j = 0;
    int sum = 0;
    while(j < n){
        if(a[i].first +d > a[j].first){
            sum -= a[j].second;
            j++;
        }
        else{
            sum += a[i].second;
            i++;
        }
        res = max(sum, res);
        // cout << sum << "\n";
    }
    cout << res << "\n";
    return 0;
}
