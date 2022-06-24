#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        if(x == 1){
            cout << 1 << endl << "1 1" << endl;
        }
        else if(x == 2){
            cout << 1 << endl << "2 1 2" << endl;
        }
        else if(x == 3){
            cout << (x/2) << endl << "3 1 2 3" << endl;
        }
        else{
            cout << (x/2) << endl << "3 1 2 3" << endl;
            string s;
            for(int i = 2; i < x/2; i++){
                s += "2 "+to_string(i*2) + " " + to_string((i*2)+1)+"\n";
            }
            cout << s;
            if(x%2 == 0){
                cout << "1 " << x;
            }
            else{
                cout << "2 " << (x-1) << " " << x;
            }
            cout << endl;
        }
    }
    return 0;
}
