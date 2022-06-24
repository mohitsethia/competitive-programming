#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    vector<int> prm = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while(t--){
        int n;
        cin >> n;
        int a[n], ans[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            ans[i] = -1;
        }
        int cur_col = 1;
        for(int p : prm){
            bool got = 0;
            for(int i = 0; i < n; i++){
                if(ans[i] != -1){
                    continue;
                }
                if(a[i] % p){
                    continue;
                }
                got = 1;
                ans[i] = cur_col;
            }
            if(got){
                cur_col++;
            }
        }
        cout << (cur_col-1) << endl;
        for(int i = 0; i < n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
