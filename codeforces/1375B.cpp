#include<iostream>
#include<algorithm>

using namespace std;

bool is_corner(int i, int j, int n, int m){
    if(i == 0 && j == 0) return true;
    if(i == 0 && j == m-1) return true;
    if(j == 0 && i == n-1) return true;
    if(j == m-1 && i == n-1) return true;
    return false;
}

bool is_side(int i, int j, int n, int m){
    if(i == 0 || j == 0 || i == n-1 || j == m-1) return true;
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int max_corner = 0;
        int max_side = 0;
        int normal = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int ch;
                cin >> ch;
                if(is_corner(i, j, n, m)) max_corner = max(max_corner, ch);
                else if(is_side(i, j, n, m)) max_side = max(max_side, ch);
                else normal = max(normal, ch);
            }
        }
        if(max_corner > 2 || max_side > 3 || normal > 4){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0;  i < n; i++){
            for(int j = 0; j < m; j++){
                if(is_corner(i, j, n, m)){
                    cout << "2 ";
                }
                else if(is_side(i, j, n, m)){
                    cout << "3 ";
                }
                else{
                    cout << "4 ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
