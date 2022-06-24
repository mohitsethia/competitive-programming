#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    bool ok = true;
    int count = 0;
    while(n > 0){
        int res = n%10;
        if(res == 4 || res == 7){
            count++;
        }
        n /= 10;
    }
    if(count == 0){
        ok = false;
    }
    while(count > 0){
        int ans = count%10;
        if(ans != 4 && ans != 7){
            ok = false;
            break;
        }
        count /= 10;
    }
    if(ok){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
