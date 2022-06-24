#include<iostream>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int count = 0, i, N, H, Y1, Y2, L;
        cin >> N >> H >> Y1 >> Y2 >> L;
        int t[N], x[N];
        for(i = 0; i < N; i++){
            cin >> t[i] >> x[i];
        }
        for(i = 0; i < N; i++){
            if(t[i] == 1){
                if(x[i] >= H-Y1){
                    count++;
                }
                else{
                    if(L == 1){
                        break;
                    }
                    else{
                        L--;
                        count++;
                    }
                }
            }
            else{
                if(x[i] <= Y2){
                    count++;
                }
                else{
                    if(L == 1){
                        break;
                    }
                    else{
                        L--;
                        count++;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
