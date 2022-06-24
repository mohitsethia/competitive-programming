#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], sum = 0;
        map<int, int> freq;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            freq[a[i]]++;
        }
        sum = a[0];
        int flag = 1;
        for(int i = 1; i < n; i++){
            if((sum | a[i]) == sum){
                flag = 0;
                break;
            }
            sum = sum|a[i];
        }
        sum = a[n-1];
        for(int i = n-2; i >= 0; i--){
            if((sum | a[i]) == sum){
                flag = 0;
                break;
            }
            sum = sum|a[i];
        }
        if(!flag){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
