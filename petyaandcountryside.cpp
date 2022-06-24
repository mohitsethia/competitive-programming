#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> h(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    vector<vector<int> > a(n+1, vector<int>(2,0));
    a[1][0] = 1;
    for(int i = 2; i <= n; i++){
        if(h[i] >= h[i-1]){
            a[i][0] = 1 + a[i-1][0];
        }
        else{
            a[i][0] = 1;
        }
    }
    a[n][1] = 1;
    for(int i = n-1; i > 0; i--){
        if(h[i] >= h[i+1]){
            a[i][1] = 1 + a[i+1][1];
        }
        else{
            a[i][1] = 1;
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        ans = max(ans, a[i][0] + a[i][1]);
    }
    cout << ans-1 << endl;
    return 0;
}
