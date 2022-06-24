#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, w[10001], i, min = 100000, sum = 0;
        cin >> n;
        for(i = 0; i < n; i++){
            cin >> w[i];
            if(w[i] < min){
                min = w[i];
            }
            sum += w[i];
        }
        cout << (sum - (n * min)) << endl;
    }
    return 0;
}
