#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        for(int i = 0; i < x; i++){
            if(i % 2 == 0){
                for(int j = 0; j < y; j++){
                    if(j % 2 == 0){
                        cout << "B";
                    }
                    else{
                        cout << "W";
                    }
                }
                cout << endl;
            }
            else{
                for(int j = 0; j < y; j++){
                    if(j % 2 == 0){
                        cout << "W";
                    }
                    else{
                        cout << "B";
                    }
                }   
                cout << endl;
            }
        }
    }
    return 0;
}
