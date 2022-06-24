#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;
    while(scanf("%d", &n)){
        if(n == -1){
            break;
        }
        int a[n], sum = 0, ctm = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        if(sum % n != 0){
            cout << "-1" << endl;
        }
        else{
            int r = sum/n;
            for(int i = 0; i < n; i++){
                if(a[i] - r > 0){
                    ctm += (a[i] - r);
                }
            }
            cout << ctm << endl;
        }
    }
    return 0;
}
