#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, res1 = 0, sum = 0, res2 = 0, m, x;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x;
            sum += x;
            res1 = max(sum, res1);
        }
        sum = 0;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> x;
            sum += x;
            res2 = max(res2, sum);
        }
        cout << res1 + res2 << endl;
    }
    return 0;
}
