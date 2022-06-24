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
    sort(a.begin(), a.end());
    int t = 10;
    int cnt = 0;
    int time = 0;
    for(int i = 0; i < n; i++){
        t += a[i];
        if(t > 720) break;
        cnt++;
        time += max(0ll, t - 360);
    }
    cout << cnt << " " << time << "\n";
    return 0;
}
