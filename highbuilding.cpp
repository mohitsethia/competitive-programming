#include<iostream>
#include<string>

using namespace std;
int main(){
    int t;
    cin >> t;
    int tc = 1;
    while(t--){
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string s1, s2, s3;
        int cnt = 0;
        for(int i = 1; i <= c; i++){
            s2 += char(n-'0') + " ";
            cnt++;
        }
        for(int i = b-c; i >= 1; i--){
            s3 += char(i-'0') + " ";
            cnt++;
        }
        for(int i = 1; i <= a-c; i++){
            s1 += char(i-'0') + " ";
        }
        cout << "Case #" << tc++ << ": ";
        cout << s1;
        while(cnt < n){
            cout << "1 ";
            cnt++;
        }
        cout << s2 << s3 << endl;
    }
    return 0;
}
