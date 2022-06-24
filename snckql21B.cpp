#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int india = 0, eng = 0;
        for(int i = 0; i < 5; i++){
            int x;
            cin >> x;
            india += x == 1;
            eng += x == 2;
        }
        if(india > eng){
            cout << "INDIA\n";
        }
        else if(india == eng) cout << "DRAW\n";
        else cout << "ENGLAND\n";
    }
    return 0;
}
