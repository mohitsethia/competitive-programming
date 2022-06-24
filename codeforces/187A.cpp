#include<iostream>
#include<algorithm>

using namespace std;

#define int long long

int32_t main(){
    int n;
    cin >> n;
    vector<int> A(n), posB(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        posB[x-1] = i;
    }
    int free = 0;
    int curr_pos = -1;
    for(int i = 0; i < n; i++){
        if(posB[A[i]-1] < curr_pos) break;
        curr_pos = posB[A[i]-1];
        free++;
    }
    cout << n - free << "\n";
    return 0;
}
