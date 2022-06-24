#include<iostream>

#define int long long
using namespace std;

int32_t main(){
    int n;
    cin >> n;
    int a[n+1], even[n+1], odd[n+1];
    even[0] = odd[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        even[i] = odd[i] = 0;
        if(i%2 == 0) even[i] += a[i];
        else odd[i] += a[i];
    }
    for(int i = 1; i <= n; i++){
        even[i] += even[i-1];
        odd[i] += odd[i-1];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(even[i-1] + odd[n] - odd[i] == odd[i-1] + even[n] - even[i]) cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
