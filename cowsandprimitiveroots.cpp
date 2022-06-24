#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int p;
    cin >> p;
    int count = 0;
    for(int i = 1; i < p; i++){
        bool ok = true;
        int x = 1;
        for(int j = 1; j < p-1; j++){
            x *= i;
            x %= p;
            if(x == 1){
                ok = false;
                break;
            }
        }
        if(ok){
            x *= i;
            x %= p;
            if(x == 1){
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
