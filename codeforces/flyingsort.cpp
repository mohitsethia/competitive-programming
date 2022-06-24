#include<iostream>
#include<climits>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], lesser = 0, greater = 0;
        cin >> a[0];
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i] <= a[0]){
                lesser++;
            }
        }
        for(int i = 1; i < n; i++){
            if(a[0] == a[i]){
                lesser--;
            }
            else{
                break;
            }
        }
        if(n-2 >= 0){
            for(int i = n-2; i >= 0; i--){
                if(a[i] >= a[n-1]){
                    greater++;
                }
            }
        }
        if(n-2 >= 0){
            for(int i = n-2; i >= 0; i--){
                if(a[i] == a[n-1]){
                    greater--;
                }
                else{
                    break;
                }
            }
        }
        if(n == 2){
            if(a[0] > a[1]){
                lesser = 1;
                greater = 0;
            }
        }
        cout << lesser+greater << endl;
    }
    return 0;
}
