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
    int n = s.length();
    int cnt = 0;
    long long number = 0;
    int len_two = 0;
    for(int i = 0; i < n; i++){
        if((s[i]-'0')%3 == 0){
            cnt++;
            number = 0ll;
            len_two = 0;
            continue;
        }
        len_two = len_two*10 + (s[i]-'0');
        if(len_two%3 == 0){
            len_two = 0;
            cnt++;
            number = 0;
            continue;
        }
        else if(len_two >= 10 && len_two < 100){
            len_two = s[i]-'0';
        }
        number = number*10ll + (s[i] -'0')*1ll;
        if(number%3 == 0){
            number = 0;
            len_two = 0;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
