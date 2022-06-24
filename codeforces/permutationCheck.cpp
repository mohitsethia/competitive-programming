#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n];
    int xorVal = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        xorVal ^= (i+1);
    }
    for(int i = 0; i < n; i++){
        xorVal ^= a[i];
    }
    if(xorVal == 0){
        puts("Yes");
    }
    else{
        puts("No");
    }

    return 0;
}
