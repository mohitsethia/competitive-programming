#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    if(n >= 42) {
        cout << "AGC0" << n+1;
    }
    else {
        cout << "AGC0";
        if(n < 10) {
            cout << "0" << n;
        }
        else {
            cout << n;
        }
    }
    return 0;
}
