#include <iostream>
#include <algorithm>

using namespace std;

int n;

int ask(int x, int y, int z) {
    cout << "? " << x+1 << " " << y%n+1 << " " << z%n+1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        int res[n];
        for(int i = 0; i < n; i++) {
            res[i] = ask(i, i+1, i+2);
        }
        vector<int> imp;
        for(int i = 0; i < n; i++) {
            if(res[i] != res[(i+1)%n]) {
                if(res[i] == 0) imp.push_back(i+1);
                else {
                    imp.push_back((i+3)%n+1);
                }
                for(int j = 0; j < n; j++) {
                    if(j != i && j != (i+3)%n) {
                        int r = ask(i, i+3, j);
                        if(r == 0) {
                            imp.push_back(j+1);
                        }
                    }
                }
                cout << "! " << imp.size();
                for(int x: imp) {
                    cout << " " << x;
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
