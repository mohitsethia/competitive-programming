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
        int arr[n], freq[200005] = {0};
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr+n);
        bool print = false;
        for(int i = 0; i < n; i++){
            freq[arr[i]]++;
            if(freq[arr[i]] > 2){
                cout << "NO" << endl;
                print = true;
                break;
            }
            if(i == n-1 && freq[arr[i]] == 2){
                cout << "NO" << endl;
                print = true;
                break;
            }
        }
        if(!print){
            cout << "YES" << endl;
            for(int i = 0; i < n; i++){
                if(freq[arr[i]] == 2){
                    cout << arr[i] << " ";
                    freq[arr[i]]--;
                }
            }   
            for(int i = n-1; i >= 0; i--){
                if(freq[arr[i]] == 1){
                    cout << arr[i] << " ";
                    freq[arr[i]]--;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
