#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i].first >> w[i].second;
        w[i].first *= 2;
    }
    int k;
    cin >> k;
    vector<vector<int>> dp(n, vector<int>(k+1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j-w[i].first >= 0) {
                dp[i][j] = dp[i][j-w[i].first]+w[i].second;
            }
            if(i > 0) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
    }
    cout << dp[n-1][k];
    return 0;
}























/*
#include <iostream>
#include <algorithm>

using namespace std;

#define all(a) a.begin(), a.end()

int Budget;

vector<int> calc(vector<int> &a, vector<int> &b) {
    vector<int> res;
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] + b[j] <= Budget) {
                res.push_back(a[i]+b[j]);
            } else {
                break;
            }
        }
    }
    return res;
}

int binarySearch(vector<int> &a, vector<int> &b) {
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i]+b[0] <= Budget) {
            int l = 0, r = b.size()-1;
            int k = 0;
            while(l <= r) {
                int mid = (l+r)/2;
                if(a[i]+b[mid] <= Budget) {
                    k = mid;
                    l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            ans += k+1;
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> a(4);
    for(int i = 0; i < 4; i++) {
        int k;
        cin >> k;
        a[i] = vector<int>(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    sort(all(a[0]));
    sort(all(a[1]));
    sort(all(a[2]));
    sort(all(a[3]));
    cin >> Budget;
    vector<int> b = calc(a[0], a[1]);
    vector<int> c = calc(a[2], a[3]);
    int ans = binarySearch(b, c);
    cout << ans << "\n";
    return 0;
}
*/
