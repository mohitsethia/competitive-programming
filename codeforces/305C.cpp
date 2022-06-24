#include <algorithm>
#include <iostream>

using namespace std;

const int N = 100000;

int aa[N];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> aa[i];
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ) {
        while (j < n && aa[j] == aa[i])
            j++;
        int k = j - i;
        if (k % 2)
            cnt++;
        i = j - k / 2;
        for (int h = i; h < j; h++)
            aa[h]++;
    }
    cout << aa[n - 1] + 1 - cnt << '\n';
    return 0;
}
