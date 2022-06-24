#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, l;
        cin >> n >> k >> l;
        if(n > k*l || (k == 1 && l > 1 && n > 1)){
            cout << "-1" << endl;
            continue;
        }
        int over = 0, i = 1;
        while(over != n){
            over++;
            cout << i << " ";
            if(i == k){
                i = 0;
            }    
            i++;
        }
        cout << endl;
    }
    return 0;
}
