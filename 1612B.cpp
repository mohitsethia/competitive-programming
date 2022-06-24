#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, a, b;
        cin >> n >> a >> b;
        if((a < b && (a > n/2 || b <= n/2)) || (a > b+1) || (a == b+1 && b != n/2)){
            cout << "-1\n";
        }
        else{
            cout << a << " ";
            int x = n;
            for(int i = 1; i < n/2;){
                if(x != b){
                    cout << x << " ";
                    i++;
                }
                x--;
            }
            cout << b << " ";
            x = 1;
            for(int i = 1; i < n/2; ){
                if(x != a){
                    cout << x << " ";
                    i++;
                }
                x++;
            }
            cout << "\n";
        }
    }
    return 0;
}
