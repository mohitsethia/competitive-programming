#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k, l;
        cin >> n >> k >> l;
        int p[n];
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(i != 0 && p[i] == l){
                int a = p[i-1] + k;
                if(a > l){
                    int count = 0;
                    for(int j = i-1; j >= 0; j--){
                        a = p[j] + k;
                        if(a > l){
                            count++;
                        }
                        if(count >= k || (j == 0 && a >= l)){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(p[i] > l){
                flag = false;
            }
        }
        if(flag){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
