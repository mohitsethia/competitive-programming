#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>

#define int long long
using namespace std;

int32_t main(){
    int t = 1;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << n << "\n";
        for(int i = 1; i <= n; i++){
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
