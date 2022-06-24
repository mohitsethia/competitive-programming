#include <iostream>
#include <algorithm>

using namespace std;

int vis[8][8] = {0};

void findNextForKnight(int row, int col) {
    int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    for (int i = 0; i < 8; i++) {
        int x = row + X[i];
        int y = col + Y[i];
        if (x >= 0 && y >= 0 && x < 8 && y < 8) {
            vis[x][y] = 1;
        }
    }
}

void findNextForRook(int row, int col) {
    for(int i = 0; i < 8; i++) {
        vis[row][i] = 1;
        vis[i][col] = 1;
    }
}

int main() {
    string s, t;
    cin >> s >> t;
    int r1 = s[0]-'a';
    int r2 = t[0]-'a';
    int c1 = s[1]-'0';
    int c2 = t[1]-'0';
    c1--;
    c2--;
    int cnt = 0;
    auto dist = [](int x1, int y1, int x2, int y2) {
        return (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    };
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i == r1 || j == c1) continue;
            if(i == r2 && j == c2) continue;
            if(dist(i, j, r1, c1) == 5 || dist(i, j, r2, c2) == 5) continue;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
