#include<iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    if(!k){
        cout << 1 << ' ' << 1 << endl << 100 << endl;
    }
    else{
        cout << 3 << ' ' << 3 << endl;
        int all_one = (1 << 18) - 1;
        int pw17 = 1 << 17;
        cout << all_one << ' ' << all_one << ' ' << pw17 << endl;
        cout << all_one << ' ' << k << ' ' << pw17+k << endl;
        cout << pw17 << ' ' << pw17+k << ' ' << k << endl;
    }
    return 0;
}
