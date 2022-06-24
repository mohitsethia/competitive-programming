#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    int tc = 1;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int freq[2] = {0};
        for(int i = 0; i < n; i++){
            freq[s[i]-'A']++;
        }
        char c = 'Y';
        if(abs(freq[0] - freq[1]) == 1){
            c = 'Y';
        }
        else{
            c = 'N';
        }
        cout << "Case #" << tc++ << ": " << c << endl;
    }
    return 0;
}
