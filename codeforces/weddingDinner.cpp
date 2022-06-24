#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = n+2;
    while(n--){
        string s;
        cin >> s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                ans++;
                break;
            }
        }
    }
    if(ans != 13){
        cout << 100*ans;    
    }
    else{
        cout << 100*(++ans);
    }
    return 0;
}
