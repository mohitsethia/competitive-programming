#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int d = min(n, s);
        cout << d-(s-d) << "\n";
    }
    return 0;
}
