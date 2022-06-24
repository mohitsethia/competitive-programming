#include<iostream>
#include<cstring>
using namespace std;
int shuffle(string s1, string s2);
int permute(string a, string b, int l, int r){
    if(l == r){
        if(shuffle(a, b) != -1){
            return 0;
        }
    }
    else{
        for(int i = l; i <= r; i++){
            swap(a[l], a[i]);
            permute(a, b, l + 1, r);
            swap(a[l], a[i]);
        }
    }
    return -1;
}
int shuffle(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(s2[i+j] != s1[j]){
                break;
            }
        }
        if(j == m){
            return i;
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string p, h;
        cin >> p >> h;
        int l = 0, r = p.length();
        int ans = permute(p, h, l, r - 1);
        if(ans == -1){
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}
