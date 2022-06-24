#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define int long long
#define type first
#define dist second
#define piece pair<char, int>

const int inf = 1e18;

bool onLine(int x, int y, int kx, int ky){
    return (kx == x || ky == y);
}

bool diagonal(int x, int y, int kx, int ky){
    return (abs(kx-x) == abs(ky-y));
}

bool queen(int x, int y, int kx, int ky){
    if(onLine(x, y, kx, ky)) return true;
    if(diagonal(x, y, kx, ky)) return true;
    return false;
}

bool bishop(int x, int y, int kx, int ky){
    return diagonal(x, y, kx, ky);
}

bool rook(int x, int y, int kx, int ky){
    return onLine(x, y, kx, ky);
}

int32_t main(){
    piece p[3][3];
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) p[i][j].dist = inf;
    }
    for(int i = 0; i < n; i++){
        char c;
        int x;
        int y;
        cin >> c >> x >> y;
        if(x == a){
            if(y > b){
                if(y-b < p[0][1].dist) p[0][1] = {c, y-b};
            }
            else if(b-y < p[0][2].dist) p[0][2] = {c, b-y};
        }
        else if(y == b){
            if(x > a){
                if(x-a < p[1][0].dist) p[1][0] = {c, x-a};
            }
            else if(a-x < p[2][0].dist) p[2][0] = {c, a-x};
        }
        else if(abs(a-x) == abs(b-y)){
            int sx = (x < a) ? 2 : 1;
            int sy = (y < b) ? 2 : 1;
            int d = abs(a-x);
            if(d < p[sx][sy].dist) p[sx][sy] = {c, d};
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(p[i][j].dist == inf) continue;
            if(p[i][j].type == 'Q'){
                cout << "YES\n";
                return 0;
            }
            if((!i || !j) && (p[i][j].type == 'R')){
                cout << "YES\n";
                return 0;
            }
            if(i && j && (p[i][j].type == 'B')){
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}
