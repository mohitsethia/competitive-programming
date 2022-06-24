#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = n; i > 0; i--){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
