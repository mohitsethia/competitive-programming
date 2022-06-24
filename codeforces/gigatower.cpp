#include<iostream>
#include<math.h>
#include<cstdlib>

int find8(int x){
    int digit, v = 0, m = abs(x);
    while(m > 0){
        if(m % 10 == 8){
            v = 1;
            break;
        }
        m /= 10;
    }
/*
    for(int i = abs(x); i > 0; i /= 10){
        if(i % 10 == 8){
            v = 1;
            break;
        }
    }
*/
    if(v == 1){
        return 1;
    }
    else{
        return 0;
    }
}
int min(int a, int b){
    return a < b ? a : b;
}
using namespace std;

int main(){
    int n, i, j = 1000000000;
    cin >> n;
    for(i = n + 1; i <= n + 20; i++){
        if(find8(i) == 1){
            j = min(j, abs(n-i));
        }
    }
    cout << j;
    return 0;
}
