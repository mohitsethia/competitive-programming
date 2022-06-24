#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a[10];
        int n = 2;
        for(int i = 0; i < 10; i++){
            cin >> a[i];
        }
        sort(a, a+10);
        cout << a[n-1] << endl;
    }
    return 0;
}
