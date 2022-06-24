#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    if(!x && !y){
        cout << "0\n";
        return 0;
    }
    int k = 0;
    if(x > 0 && y > (-x)-1 && y <= x) k = 4*(x-1)+1;
    if(y > 0 && x >= (-y)  &&  x < y) k = y*4 -2;
    if(x < 0 && y >= x  &&  y < (-x)) k = 4*(-x)-1;
    if(y <= 0 && x > y && x <= (-y)+1) k = 4*(-y);
    cout << k << endl;
    return 0;
}
