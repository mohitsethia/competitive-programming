#include<iostream>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        pair<int, int> freq[100005];
        for(int i = 0; i < m; i++){
            freq[i].first = 0;
            freq[i].second = 0;
        }
        int flag = 0, check = 0;
        for(int i = 0; i < n; i++){ 
            int x;
            cin >> x;
            if(x < m){
                freq[x].first++;
                freq[x].second = i;
            }
            if(x == m){
                flag = 1;
            }
            if(x > m){
                check = 1;
            }
        }   
        if(flag == 0 && check == 1){
            int idx = 0;
            for(int i = 1; i < m; i++){
                if(freq[i].first == 0){
                    if(i+1 < m){
                        if(freq[i+1].first != 0){
                            idx = freq[i+1].second;
                        }
                    }
                    else{
                        idx = n+1;
                        break;
                    }
                }
            }
            cout << n-idx << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
    return 0;
}
