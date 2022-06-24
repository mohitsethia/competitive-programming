#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<int> > a(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                a[i].push_back(x);
            }
        }
        for(int i = 0; i < n; i++){
            cout << a[i][0] << " ";
        }
        cout << endl;
    }
    return 0;
}
