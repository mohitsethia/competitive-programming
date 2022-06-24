#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
void solve(){
    int k;
    string s;
    cin >> k >> s;
    int n = (1 << k)-1;
    vector<int> winners(1 << (k+1));
    for(int i = (1 << k); i < (1 << (k+1)); i++){ // leaf nodes
        winners[i] = 1;
    }
    s += '&';
    reverse(s.begin(), s.end());
    for(int i = n; i > 0; i--){
        if(s[i] == '0'){
            winners[i] = winners[2*i+1];
        }
        else if(s[i] == '1'){
            winners[i] = winners[2*i];
        }
        else{
            winners[i] = winners[2*i] + winners[2*i+1];
        }
    }
    int q;
    cin >> q;
    while(q--){
        int p;
        char c;
        cin >> p >> c;
        p = (1 << k)-p;
        s[p] = c;
        while(p > 0){
            if(s[p] == '0'){
                winners[p] = winners[2*p+1];
            }
            else if(s[p] == '1'){
                winners[p] = winners[2*p];
            }
            else{
                winners[p] = winners[2*p] + winners[2*p+1];
            }
            p = (p)/2;
        }
        cout << winners[1] << "\n";
    }
}

    

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
