#include<iostream>
#include<map>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> fqx;
        map<int, int> fqy;
        for(int i = 0; i < 4*n -1; i++){
            int x, y;
            cin >> x >> y;
            fqx[x]++;
            fqy[y]++;
        }
        int x, y;
        for(auto it:fqx){
            if((it.second)%2 != 0){
                x = it.first;
                break;
            }
        }
        for(auto it:fqy){
            if((it.second)%2 != 0){
                y = it.first;
                break;
            }
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
