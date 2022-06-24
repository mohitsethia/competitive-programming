#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], c[n];
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int pos = n-1;
        while(pos > 0 && a[pos-1] >= a[pos]){
            --pos;
        }
        while(pos > 0 && a[pos-1] <= a[pos]){
            --pos;
        }
        cout << pos << endl;
    }
    return 0;
}
