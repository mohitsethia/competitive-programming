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
        int a[n], odd = 0, even = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i%2 == 0){
                even += a[i];
            }
            else{
                odd += a[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(even < odd){
                if(i%2 == 0){
                    cout << "1 ";
                }
                else{
                    cout << a[i] << " ";
                }
            }
            else{
                if(i%2 != 0){
                    cout << "1 ";
                }
                else{
                    cout << a[i] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
