#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int> > athletes(5, vector<int>(n));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < 5; j++){
                cin >> athletes[j][i];
            }
        }
        if(n == 1){
            cout << "1\n";
        }
        else{
            bool ok = true;
            int best = 0;
            for(int i = 1; i < n; i++){
                int cnt = 0;
                for(int j = 0; j < 5; j++){
                    if(athletes[j][best] < athletes[j][i]){
                        cnt++;
                    }
                }
                if(cnt < 3){
                    best = i;
                }
            }
            for(int i = 0; i < n; i++){
                if(i == best) continue;
                int cnt = 0;
                for(int j = 0; j < 5; j++){
                    if(athletes[j][best] < athletes[j][i]){
                        cnt++;
                    }
                }
                if(cnt < 3){
                    ok = false;
                }
            }
            if(!ok) best = -2;
            cout << best+1 << "\n";
        }
    }
    return 0;
}
