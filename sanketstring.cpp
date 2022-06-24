#include<iostream>
#include<string>
using namespace std;
int main(){
    int k;  
    cin >> k;
    string str;
    cin >> str;
    int freq[2] = {};
    int left = 0, ans = 0;
    for(int i = 0; i < str.length(); i++){
        char temp = str[i];
        freq[temp - 'a']++;
        if(min(freq[0], freq[1]) > k){
            freq[str[left] - 'a']--;
            left++;
        }
        else{
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
