#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double x1, y1, r1, x2, y2, r2, k = 0;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
    if(dist > r1+r2){
        k = dist-r1-r2;
    }
    else if(dist < abs(r1-r2)){
        k = abs(r1-r2)-dist;
    }
    cout << fixed << setprecision(18) << k/2 << endl;
    return 0;
}
