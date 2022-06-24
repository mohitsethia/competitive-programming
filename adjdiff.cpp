#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int a[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int k = 0;
        sort(a,a+n);
        for(int i = 0; i < n; i++){
            b[n-i-1-k] = a[i];
            k++;
        }
        k = 0;
        for(int i = 0; i < n; i++){
            b[n-i-2-k] = a[n-i-1];
            k++;
        }
        for(int i = 0; i < n; i++){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
