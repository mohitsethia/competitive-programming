#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n, count10 = 0, count11 = 0, count20 = 0, count21 = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x == 0){
            count10++;
        }
        else{
            count11++;
        }
        if(y == 0){
            count20++;
        }
        else{
            count21++;
        }
    }
    int ans1 = 0, ans2 = 0;
    if(count10 > count11){
        ans1 = count11;
    }
    else{
        ans1 = count10;
    }
    if(count20 > count21){
        ans2 = count21;
    }
    else{
        ans2 = count20;
    }
    cout << ans1+ans2 << endl;
    return 0;
}
