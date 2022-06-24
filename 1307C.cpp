#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<vector<long long> > arr2(26, vector<long long>(26));
    vector<long long> arr1(26);
    for(int i = 0; i < (int)s.length(); i++){
        int c = s[i]-'a';
        for(int j = 0; j < 26; j++){
            arr2[j][c] += arr1[j];
        }
        arr1[c]++;
    }
    long long ans = 0;
    for(int i = 0; i < 26; i++){
        ans = max(ans, arr1[i]);
    }
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            ans = max(ans, arr2[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
