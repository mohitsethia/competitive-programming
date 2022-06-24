#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y, countx = 0, county = 0, idx1, idx2;
        cin >> n;
        int a[2] = {0};
        cin >> x;
        a[0]++;
        idx1 = 1;
        for(int i = 1; i < n; i++){
            cin >> y;
            if(x == y){
                a[0]++;
            }
            else{
                a[1]++;
                idx2 = i+1;
            }
        }
        if(a[0] > a[1]){
            cout << idx2 << endl;
        }
        else{
            cout << idx1 << endl;
        }
    }
    return 0;
}
