#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int small = 0, large = 0;
    for(int i = 0; i < n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            large++;
        }
        else{
            small++;
        }
    }
    if(small == 0 || large == 0){
        cout << "0\n";
        return 0;
    }
    int ans = INT_MAX;
    int s2 = 0, l2 = 0;
    for(int i = 0; i < n; i++){
        ans = min(ans, s2 + (large-l2));
        if(s[i] >= 'A' && s[i] <= 'Z'){
            l2++;
        }
        else{
            s2++;
        }
    }
    ans = min(ans, s2 + (large-l2));
    cout << ans << endl;
    return 0;
}
