#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        if((x+y)%2){
            cout << "-1 -1\n";
        }
        else{
            if(x%2) x--, y++;
            cout << x/2 << " " << y/2 << "\n";
        }
    }
    return 0;
}
