#include<iostream>
using namespace std;
int max_xor(int l, int r){
    int lxr = l^r;
    int msbPos = 0;
    while(lxr){
        msbPos++;
        lxr >>= 1;
    }
    int maxXor = 0;
    int two = 1;
    while(msbPos--){
        maxXor += two;
        cout << two << " two " << msbPos << " msbPos " << maxXor << " maxXor ";
        two <<= 1;
        cout << two << endl;
    }
    return maxXor;
}
int main(){
    int x, y;
    cin >> x >> y;
    cout << max_xor(x, y) << endl;
    return 0;
}   
