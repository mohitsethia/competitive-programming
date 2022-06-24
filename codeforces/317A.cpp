#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int x, y, m;
    cin >> x >> y >> m;
    if(x > y) swap(x, y);
    if(y >= m){
        cout << "0\n";
        return 0;
    }
    if(y <= 0){
        cout << "-1\n";
        return 0;
    }
    int ans = 0;
    if(x < 0){
        ans += (-x + y - 1)/y;
        x = (x%y+y)%y;
    }
    while(y < m){
        int z = x+y;
        x = y;
        y = z;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
