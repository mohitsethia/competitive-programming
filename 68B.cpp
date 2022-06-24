#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n;
    double p;
    cin >> n >> p;
    double a[n];
    p /= 100;
    for(int i = 0; i < n; i++) cin >> a[i];
    double l = 0, r = 1000;
    auto good = [&](double x){
        double x1 = 0, x2 = 0;
        for(int i = 0; i < n; i++){
            if(a[i] >= x) x1 += a[i]-x;
            else x2 += x-a[i];
        }
        x1 *= (1-p);
        return x1 >= x2;
    };
    for(int i = 0; i < 40; i++){
        double c = (l+r)/2;
        if(good(c)) l = c;
        else r = c;
    }
    printf("%.6lf\n", (l+r)/2);
    return 0;
}
