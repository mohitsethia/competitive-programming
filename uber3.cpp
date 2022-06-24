#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int getSum(int BITree[], int index)
{
    int sum = 0; // Initialize result
    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val) {
    while (index <= n) {
       BITree[index] += val;
       index += index & (-index);
    }
}

int getInvCount(vector<int> &arr, int n) {
    int invcount = 0; // Initialize result
    int maxElement = 0;
    for (int i=0; i<n; i++)
        if (maxElement < arr[i])
            maxElement = arr[i];
    int BIT[maxElement+1];
    for (int i=1; i<=maxElement; i++)
        BIT[i] = 0;
    for (int i=n-1; i>=0; i--) {
        invcount += getSum(BIT, arr[i]-1);
        updateBIT(BIT, maxElement, arr[i], 1);
    }

    return invcount;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int idx = 0, mx = 0;
    int ans = INT_MAX;
    vector<int> b, c;
    for(int i = n-1; i >= 0; i--) {
        c.push_back(a[i]);
    }
    for(int i = 0; i < n; i++) {
        b.push_back(a[i]);
        c.pop_back();
        ans = min(ans, getInvCount(b, b.size()) + getInvCount(c, c.size()));
    }
    cout << ans << "\n";
    return 0;
}
