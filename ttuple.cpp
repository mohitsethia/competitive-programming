#include<iostream>
using namespace std;
#define ll long long int
bool canbeone(int p, int q, int r, int a, int b, int c){
    int x1 = a-p;
    int x2 = b-q;
    int x3 = c-r;
    int y1 = 1, y2 = 2, y3 = 3;
    if(a%p == 0 and b%q == 0 and c%r == 0){
        y1 = a/p;
        y2 = b/q;
        y3 = c/r;
    }
    if(y1 == y2 and y2 == y3){
        return true;
    }
    if((y1 == 1 || y1 == 0) and y2 == y3){
        return true;
    }
    if((y2 == 1 || y2 == 0) and y1 == y3){
        return true;
    }
    if((y3 == 1 || y3 == 0) and y1 == y2){
        return true;
    }
    if((y1 == 1 and y2 == 1) || (y2 == 1 and y3 == 1) || (y1 == 1 and y3 == 1)){
        return true;
    }
    if(x1 == x2 and x2 == x3){
        return true;
    }
    if(x1 == 0 and x2 == x3){
        return true;
    }
    if(x2 == 0 and x1 == x3){
        return true;
    }
    if(x3 == 0 and x1 == x2){
        return true;
    }
    if((x1 == 0 and x2 == 0) || (x2 == 0 and x3 == 0) || (x1== 0 and x3 == 0)){
        return true;
    }
    return false;
}
bool canbetwo(int p, int q, int r, int a, int b, int c){
    return false;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll p, q, r, a, b, c;
        cin >> p >> q >> r >> a >> b >> c;
        if(p == a and q == b and r == c){
            cout << 0 << endl;
            continue;
        }
        if(canbeone(p, q, r, a, b, c)){
            cout << 1 << endl;
            continue;
        }
        else if(canbetwo(p, q, r, a, b, c)){
            cout << 2 << endl;
            continue;
        }
        else{
            cout << 3 << endl;
        }
    }
    return 0;
}   
