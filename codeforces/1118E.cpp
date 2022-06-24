#include<iostream>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    if(n > k*(k-1)){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int cnt = 0;
    bool done = false;
    for(int i = 0; i < k; i++){
        for(int j = i+1; j < k; j++){
            cout << i+1 << " " << j+1 << "\n";
            cnt++;
            if(cnt == n){
                done = true;
                break;
            }
            cout << j+1 << " " << i+1 << "\n";
            cnt++;
            if(cnt == n){
                done = true;
                break;
            }
        }
        if(done) break;
    }
    return 0;
}
