#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int turn = 1;
        int score = 0;
        for(int i = n-1; i >= 0; i--){
            if(turn){ // Alice
                score += a[i]%2 ? 0 : a[i];
            }
            else{ // Bob
                score -= a[i]%2 ? a[i] : 0;
            }
            turn ^= 1;
        }
        if(score == 0){
            cout << "Tie\n";
        }
        else if(score > 0){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }
    return 0;
}
