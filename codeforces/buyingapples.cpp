#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[k+1], v[k+1];
        for(int i = 1; i <= k; i++){
            cin >> a[i];
            v[i] = a[i];
        }
        for(int i = 2; i <= k; i++){
            for(int j = 1; j < i; j++){
                if(a[i-j] == -1 || v[j] == -1){
                    continue;
                }
                v[i] = min(v[i], v[j] + a[i-j]);
            }
        }
        if(k == 0){
            cout << "0" << endl;
        }
        else{
            cout << v[k] << endl;
        }
    }
    return 0;
}
