#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= 100000; i++){
            if(i%3 != 0 && i%10 != 3){
                cnt++;
            }
            if(cnt == n){
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}
