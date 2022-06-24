#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, ans = 0, flag = 0;
        cin >> n;
        int a[n];
        int coins[3] = {0};
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(a[0] > 5){
            cout << "NO" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            if(a[i] == 5){
                coins[0]++;
                //ans += 5;
            }
            if(a[i] == 10){
                coins[0]--;
                coins[1]++;
                //ans += 5;
            }
            if(a[i] == 15){
                if(coins[1] != 0){
                    coins[1]--;
                }
                else{
                    coins[0]-=2;
                }
                
                coins[2]++;
            }
            if((coins[0] < 0 || coins[1] < 0 || coins[2] < 0)){
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            cout << "YES" << endl;
        }
    }
    return 0;
}
