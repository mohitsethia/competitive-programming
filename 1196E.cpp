#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void solve(){
    int b, w;
    cin >> b >> w;
    int add = 0;
    if(b < w){
        add = 1;
        swap(b, w);
    }
    if(b > 3*w+1){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(int i = 1; i <= 2*w; i++){
        cout << i+add << " 2" << "\n";
    }
    b -= w;
    if(b > 0){
        cout << 2*w+1+add << " 2" << "\n";
        b--;
    }
    for(int i = 1; i <= b && i <= w; i++){
        cout << 2*i + add << " 3" << "\n";
    }
    b -= w;
    for(int i = 1; i <= b && i <= w; i++){
        cout << 2*i+add << " 1" << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
