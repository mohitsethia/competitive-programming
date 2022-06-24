#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int w, h, n;
        cin >> w >> h >> n;
        int cuts = 1;
        while(w%2==0 || h%2==0){
            cuts *= 2;
            if(w%2 == 0) w /= 2;
            else h /= 2;
        }
        if(cuts >= n){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
