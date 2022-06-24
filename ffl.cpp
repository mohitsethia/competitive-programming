#include<iostream>
#include<climits>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s;
        cin >> n >> s;
        int p[n], b[n];
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        for(int i = 0; i < n ;i++){
            cin >> b[i];
        }
        int min0 = 100, min1 = 100;
        for(int i = 0; i < n; i++){
            if(b[i] == 0){
                if(p[i] < min0){
                    min0 = p[i];
                }
            }
            else{
                if(p[i] < min1){
                    min1 = p[i];
                }
            }
        }
        if((s+min0+min1 <= 100)){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
    return 0;
}
