#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int curr_len = 0, max_len = 0;
        for(int i = 0; i < n; i++){
            if(a[i] % k != 0){
                curr_len++;
                max_len = max(curr_len, max_len);
            }
            else{
                curr_len = 0;
            }
            max_len = max(curr_len, max_len);
        }
        if(max_len == 0){
            cout << "-1" << endl;
        }
        else{
            cout << max_len << endl;
        }
    }   
    return 0;
}
