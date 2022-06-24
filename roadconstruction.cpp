#include<iostream>
#include<map>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    bool free[n];
    memset(free, true, sizeof(free));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        free[x-1] = false;
        free[y-1] = false;
    }
    cout << n-1 << "\n";
    for(int i = 0; i < n; i++){
        if(free[i]){
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                }
                cout << j+1 << " " << i+1 << endl;
            }
            break;
        }
    }
    return 0;
}
