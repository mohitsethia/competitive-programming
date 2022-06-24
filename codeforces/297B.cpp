#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

map <int, int> mp;

int main() {
    int n, m, k, foo;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &foo);
        mp[foo]++;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &foo);
        mp[foo]--;
    }
    long long wmax = 0, wmin = 0;
    for (auto x : mp) {
        if (x.second > 0) {
            if (wmax + wmin >= 0) {
                wmax += x.second;
            } else {
                wmax = x.second;
                wmin = 0;
            }
        } else {
            wmin += x.second;
        }
    }
    if (wmax > -wmin) puts("YES");
    else puts("NO");
    return 0;
}
