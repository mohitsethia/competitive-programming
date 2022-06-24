#include <iostream>
#include <algorithm>

using namespace std;

int ask(int i){
    cout << "? " << i+1 << endl;
    int ans;
    cin >> ans;
    return ans-1;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n, -1);
        for(int i = 0; i < n; i++) {
            if(p[i] != -1) continue;
            int start = ask(i);
            int last = start;
            int a;
            while((a = ask(i)) != start) {
                p[last] = a;
                last = a;
            }
            p[last] = a;
        }
        cout << "!";
        for(int i: p) {
            cout << " " << i+1;
        }
        cout << endl;
    }
    return 0;
}
