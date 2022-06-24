#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n, m, k;
    cin >> n >> m >> k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int change = 0, ans = 0;
    for(int j = 0; j < m; j++){
        int count = 0, prev = 0, val = 0;
        for(int i = 0; i < n; i++){
            if(a[i][j] == 1){
                count++;
                int temp = 0;
                for(int l = i; l < min(i+k, n); l++){
                    if(a[l][j] == 1) temp++;
                }
                if(temp > val){
                    val = temp;
                    prev = count-1;
                }
            }
        }
        ans += val;
        change += prev;
    }
    cout << ans << " " << change << "\n";
    return 0;
}
