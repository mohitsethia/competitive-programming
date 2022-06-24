#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<int> ind(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        ind[i] = i;
    }
    sort(ind.begin(), ind.end(), [&](const int &a, const int &b){
        for(int i = 0; i < m; i++) {
            if(s[a][i] != s[b][i]) {
                return (s[a][i] < s[b][i]) ^ (i&1);
            }
        }
        return 0;
    });
    for(int i: ind) {
        cout << i+1 << " ";
    }
    return 0;
}
