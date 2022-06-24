#include<iostream>
using namespace std;
float square_root(int n, int p){ //p is the number of decimal points
    int s = 0, e = n;
    float ans = -1;
    while(s <= e){
        int mid = (s+e)/2;
        if(mid*mid == n){
            ans = mid;
            return mid;
        }
        if(mid*mid <  n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    float inc = 0.1;
    for(int times = 1; times <= p; times++){
        while(ans*ans <= n){
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cout << "Enter the number and the decimal points: ";
        cin >> n >> p;
        cout << square_root(n, p) << endl;
    }
    return 0;
}
