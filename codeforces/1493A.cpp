#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int c = (k+1)/2;
        cout << n-c << "\n";
        for(int i = c; i <= n; i++){
            if(i == k) continue;
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
