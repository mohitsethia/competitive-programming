#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, cnt = 0;
        cin >> n;
        string a, b;
        cin >> a >> b;
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            for(char x = 'a'; x <= 't'; x++){
                char y = 'z';
                vector<int> pos;
                for(int i = 0; i < n; i++){
                    if(a[i] == x && b[i] > x){  
                        pos.push_back(i);
                        y = min(y, b[i]);
                    }
                }
                if(!pos.empty()){
                    cnt++;
                    for(int p : pos){
                        a[p] = y;
                    }
                }
            }
            cout << cnt << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
