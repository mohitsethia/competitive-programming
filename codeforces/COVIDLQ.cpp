#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], i, j, count = 0;
        for(i = 0; i < n; i++){
            cin >> a[i];    
        }
        // 0 1 0 0 0 0 0 1 0 0 0 0 0 1
        // i = 12; j = 10; (n/6+1)*5 + (n-n/6) = n + n = 2n = O(1);
        for(i = 0; i < n; i++){
            if(a[i] == 1){
                for(j = i+1; j < i + 6; j++){ 
                    if(j < n){
                        if(a[j] == 1){
                            cout << "NO" << endl;
                            count = 1;
                            i = n;
                        }
                    }
                    
                }
            }
        }
        if( count == 0){
            cout << "YES" << endl;
        }
    }
    return 0;
}
