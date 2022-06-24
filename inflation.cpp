#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        double k;
        cin >> n >> k;
        int p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        k /= 100;
        int sum = p[0];
        int inc = 0;
        for(int i = 1; i < n; i++){
            if((double)p[i]/sum > k){
                int it = ceil(p[i]/k)-sum;
                inc += it;
                sum += it;
            }
            sum += p[i];
        }
        cout << inc << endl;
    }
    return 0;
}
