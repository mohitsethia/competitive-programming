#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstdio>
#include<stdlib.h>
#include<string>
#include<cstring>
#include<unordered_map>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<chrono>
#include<random>

using namespace std;
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p){
    return os<<'('<<p.F<< ","<<p.S<<')';
}
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());


int solve(int n, int m, int l, int r, vector<vector<int> > &arr) {
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        long long sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        mp[sum]++;
    }
    int mx = 0;
    for(auto it: mp) {
        mx = max(mx, it.second);
    }
    int Xor = 0;
    if(mx == 1) {
        for(auto it: mp) {
            Xor ^= it.first;
        }
    } else {
        for(auto it: mp) {
            if(it.second == mx) {
                Xor ^= it.first;
            }
        }
    }
    return Xor;
}

int main() {
    int n, m;
    int l, r;
    cin >> n >> m >> l >> r;
    vector<vector<int>> arr(m, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << solve(n, m, l, r, arr);
    return 0;
}

/*

class Shape{
    public:
        Shape(int l, int w):length(l), width(w){}
        virtual int get_Area(){
            cout << "Parent Class\n";
            return length*width;
        }
    protected:
        int length, width;
};

class Square: public Shape{
    public:
        Square(int l = 0, int w = 0): Shape(l, w){}
        virtual int get_Area(){
            cout << "Square Area\n";
            return length*width;
        }
};

class Rhombus: public Square{
    public:
        Rhombus(int l = 0, int w = 0): Square(l, w){}
        int get_Area(){
            cout << "Rhombus Class\n";
            return length*width;
        }
};

class Rectangle: public Shape{
    public:
        Rectangle(int l = 0, int w = 0): Shape(l, w){}
        int get_Area(){
            cout << "Rectangle Area\n";
            return length*width;
        }
};

int main() {
    Shape *s = new Shape(4, 4);
    Square *sq = new Square(5, 5);
    Rhombus rh(2, 2);
    Square *B = new Rhombus(1, 1);
    cout << B->get_Area() << "\n";
    s = &rh;
    cout << s->get_Area() << "\n";
    sq = &rh;
    cout << sq->get_Area() << "\n";
    cout << rh.get_Area() << "\n";
    return 0;
}
*/
