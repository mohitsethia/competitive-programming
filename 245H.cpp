#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// #define int long long

const int N = 5e3;

string s;
vector<vector<int> > num(N+1, vector<int>(N+1, -1));
vector<vector<int> > pal(N+1, vector<int>(N+1, -1));

int isPal(int i, int j){
    if(i == j) return 1;
    if(i+1 == j) return (s[i] == s[j]);
    if(pal[i][j] != -1) return pal[i][j];
    return pal[i][j] = isPal(i+1, j-1) && (s[i] == s[j]) ? 1 : 0;
}

int getNum(int i, int j){
    if(i == j) return 1;
    if(i+1 == j) return 2 + isPal(i, j);
    if(num[i][j] != -1) return num[i][j];
    return num[i][j] = getNum(i+1, j)+getNum(i, j-1) - getNum(i+1, j-1) + isPal(i, j);
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << getNum(l, r) << "\n";
    }
    return 0;
}
