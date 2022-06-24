#include<iostream>
#include<algorithm>
#include<cmath>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int sum = 0, add = 0;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            sum += p;
            add += ceil((double)p/(double)x);
        }
        sum = ceil((double)sum/(double)x);
        cout << min(sum, add) << " " << max(sum, add) << "\n";
    }
    return 0;
}
