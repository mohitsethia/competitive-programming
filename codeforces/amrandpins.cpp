#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main(){
    long long int r, x, x2, y, y2;
    cin >> r >> x >> y >> x2 >> y2;
    double dist = sqrt(pow(x-x2, 2)+pow(y-y2, 2));
    int ans = dist/(2*r);
    if(ans*2*r == dist){
        cout << ans << endl;
    }
    else{
        cout << ans + 1 << endl;
    }
    return 0;
}
