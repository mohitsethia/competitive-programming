#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, sum = 0;
        cin >> n;
        if((n/2)%2 == 1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for(int i = 1; i <= n/2; i++){
                cout << 2*i << " ";
                sum += 2*i;
            }
            for(int i = 1; i < n/2; i++){
                cout << 2*i-1 << " ";
                sum -= ((2*i) -1);
            }
            cout << sum << endl;
        }
    }
    return 0;
}
