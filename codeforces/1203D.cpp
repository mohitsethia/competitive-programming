#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int cnt = 0;
    int j = 0;
    int n = s.size();
    int m = t.size();
    vector<int> f(m+10), l(m+10);
    for(int i = 0; i < n; i++){
        if(j < m && s[i] == t[j]){
            f[j] = i;
            j++;
        }
    }
    j = m-1;
    for(int i = n-1; i >= 0; i--){
        if(j >= 0 && s[i] == t[j]){
            l[j] = i;
            j--;
        }
    }
    cnt = l[0];
    cnt = max(cnt, n-1-f[m-1]);
    for(int i = 1; i < m; i++){
        int curr = l[i]-f[i-1]-1;
        cnt = max(cnt, curr);
    }
    cout << cnt << "\n";
    return 0;
}
