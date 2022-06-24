#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
#define mod 1000000007
int32_t main(){
    int x, y, n;
    cin >> x >> y >> n;
    int choice = n%6;
    if(choice == 1){
        cout << (x+mod)%mod << endl;
    }
    else if(choice == 2){
        cout << (y+mod)%mod << endl;
    }
    else if(choice == 3){
        cout << ((y-x)%mod+mod)%mod << endl;
    }
    else if(choice == 4){
        cout << (-x+mod)%mod << endl;
    }
    else if(choice  == 5){
        cout << (-y+mod)%mod << endl;
    }
    else{
        cout << ((x-y)%mod+mod)%mod << endl;
    }
    return 0;
}
