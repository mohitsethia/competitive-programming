#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, i;
        cin >> n >> k;
        int a[n], sum = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum <= k){
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}
