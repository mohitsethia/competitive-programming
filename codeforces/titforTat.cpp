#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0, j = n-1;
        while(k--){
            while(a[i] == 0 && i < n-1){
                i++;
            }
            a[i]--, a[n-1]++;
        }
        for(int m = 0; m < n; m++){
            cout << a[m] << " ";
        }
        cout << endl;
    }
    return 0;
}
