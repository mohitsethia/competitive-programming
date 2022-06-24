#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int d, m;
        cin >> d >> m;
        int ans = 1;
        for(int i = 0; (1 << i) <= d; i++){
            int cnt = min(d+1, (1ll << (i+1))) - (1 << i);
            ans = (ans *(cnt+1))%m;
        }
        cout << (ans +m -1)%m << "\n";
    }
    return 0;
}
