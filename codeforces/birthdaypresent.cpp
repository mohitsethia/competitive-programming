#include<iostream>
using namespace std;
bool isSorted(int *a, int n){
    int count = 0;
    for(int i =0; i < n -1; i++){
        if(a[i] > a[i+1]){
            count = 1;
        }
    }
    if(count == 1){
        return false;
    }
    else{
        return true;
    }
}
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
        if(k <= 1){
            cout << "yes" << endl;
        }
        else{
            if(isSorted(a, n)){
                cout << "yes" << endl;
            }
            else{
                for(int j = 0; j < k; j++){
                    for(int i = 0; i < n - k; i++){
                        if(a[i] > a[i+k]){
                            swap(a[i], a[i+k]);
                        }
                    }
                }
                if(isSorted(a, n)){
                    cout << "yes" << endl;
                }
                else{
                    cout << "no" << endl;
                }
            }
        }
    }
    return 0;
}
