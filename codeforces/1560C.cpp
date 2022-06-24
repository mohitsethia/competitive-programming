#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int x = (int)(ceil(sqrt(k)));
        int y = x-1;
        int diff = k- y*y;
        int row = min(x, diff);
        int col = x - max(diff-x, 0);
        cout << row << " " << col << "\n";
    }
    return 0;
}
