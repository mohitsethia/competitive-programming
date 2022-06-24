#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0, j = n-1, k = 0;
        while(i <= j && k < n){
            b[k++] = a[i++];
            if(k < n){
                b[k++] = a[j--];
            }
        }
        for(int i = 0; i < n; i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
