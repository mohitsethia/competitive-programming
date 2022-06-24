#include<iostream>
#include<set>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        int a[r][c];
        set<int> n;
        set<int> m;
        int ash = 0, vivek = 0;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> a[i][j];
                if(a[i][j] == 1){
                    n.insert(i);
                    m.insert(j);
                }
            }
        }
        int mn = min(r-n.size(), c-m.size());
        if(mn%2){
            cout << "Ashish" << endl;
        }
        else{
            cout << "Vivek" << endl;
        }
    }
    return 0;
}
