#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int mx = 1;
    for(int i = 2; i <= 10; i++){
        if(n%i == 0){
            mx = i;
        }
    }
    cout << mx << endl;
    return 0;
}
