#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string s;
    cin >> s;
    map<char, int> freq;
    int maxfreq = 0;
    char a;
    for(int i = 0; i < s.length(); i++){
        freq[s[i]]++;
        if(maxfreq < freq[s[i]]){
            a = s[i];
            maxfreq = freq[s[i]];
        }
    }
    cout << a << endl;
    return 0;
}
