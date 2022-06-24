#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MID 128

int d[] = { 1, -1 };

int dp[256][2][128][64];
bool vis[256][2][128][64];
string s;

int go(int cur, int dir, int idx, int left) {
    if (idx == (int)s.size()) {
        if (left % 2 != 0) return -1;
        return max(MID-cur, cur-MID);
    }
    if (vis[cur][dir][idx][left]) return dp[cur][dir][idx][left];

    int nxt, nxtdir;
    if (s[idx] == 'T') { nxt = cur; nxtdir = 1-dir; }
    else { nxt = cur + d[dir]; nxtdir = dir; }
    int res = go(nxt, nxtdir, idx+1, left);

    if (left > 0) {
        if (s[idx] == 'T') { nxt = cur + d[dir]; nxtdir = dir; }
        else { nxt = cur; nxtdir = 1-dir; }
        res = max(res, go(nxt, nxtdir, idx+1, left-1));
    }

    vis[cur][dir][idx][left] = true;
    return dp[cur][dir][idx][left] = res;
}

int main() {
    memset(vis, 0, sizeof(vis));

    cin >> s;
    int n; cin >> n;
    cout << go(MID, 0, 0, n) << endl;
    return 0;
}

