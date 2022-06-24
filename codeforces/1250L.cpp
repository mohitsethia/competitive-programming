#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        if(a > c) swap(a, c);
        int g[3];
        g[0] = c/2;
        g[1] = c-c/2;
        g[2] = a;
        while(b){
            sort(g, g+3);
            g[0]++;
            b--;
        }
        cout << max(g[0], max(g[1], g[2])) << "\n";
    }
    return 0;
}
