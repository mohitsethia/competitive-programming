#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    bool flag = true;
    while(n > 1 && flag){
        cout << n << " ";
        flag = false;
        for(int i = 2; i <= sqrt(n); i++){
            if(n%i == 0){
                flag = true;
                n /= i;
                break;
            }
        }
    }
    cout << 1 << "\n";
    return 0;
}
