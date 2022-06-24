#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int, int> idx, L, rem;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            idx[x] = i;
            rem[i] = x;
        }
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            L[rem[i]] = x;
        }
        int val = idx[1];
        int jump = 0;
        int hit = 0;
        for(int j = 0; j < 3; j++){
            val = idx[1];
            for(int i = 2; i <= n; i++){
                if(idx[i] <= val){
                    jump = ((val-idx[i])/L[i]) + 1;
//                    cout << val << " " << jump << " " << idx[i] << " " << L[i] << endl;
                    int temp = idx[i] + L[i]*jump;
                    idx[i] = temp;
                }
                val = idx[i];
                hit += jump;
                jump = 0;
            }
        }
        cout << hit << endl;
    }
    return 0;
}
