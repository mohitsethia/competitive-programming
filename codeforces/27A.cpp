#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[3002] = {0};
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 1; i <= 3001; i++) {
        if(a[i] == 0) {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}
