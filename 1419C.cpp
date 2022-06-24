#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define int long long
using namespace std;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int cnt = 0, sum = 0;
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            cnt += (k == x);
            sum += k;
        }
        if(cnt == n){
            cout << "0\n";
        }
        else if(cnt > 0){
            cout << "1\n";
        }
        else if(sum == n*x){
            cout << "1\n";
        }
        else{
            cout << "2\n";
        }
    }
    return 0;
}
