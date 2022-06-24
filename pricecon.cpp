#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, ans = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++){
            int p;
            cin >> p;
            if(p > k){
                ans += (p-k);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
