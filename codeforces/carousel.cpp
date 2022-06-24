#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], count = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            int j;
            for(j = 0; j < i; j++){
                if(a[i] == a[j]){
                    break;
                }
            }
            if(j == i){
                count++;
            }
        }
        cout << count << endl;
        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
