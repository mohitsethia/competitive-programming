#include<iostream>
#include<cstring>
#include<climits>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s, p;
        cin >> s >> p;
        int str[26] = {0};
        int pat[26] = {0};
        for(int i = 0; i < s.length(); i++){
            str[s[i] - 'a']++;
        }
        char second  = p[0];
        for(int i = 0; i < p.length(); i++){
            pat[p[i] - 'a']++;
            if(second == p[0]){
                if(p[i] != p[0]){
                    second = p[i];
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(i < (p[0] - 'a')){
                while(str[i] > pat[i]){
                    printf("%c", i+'a');
                    str[i]--;
                }
            }
            else if(i == (p[0] - 'a')){
                char c = i+'a';
                int flag = 0;
                    if(second < p[0]){
                        flag = 1;
                    }
                if(!flag){
                    while(str[i] > pat[i]){
                        printf("%c", i+'a');
                        str[i]--;
                    }
                }
                cout << p;
                for(int j = 0; j < 26; j++){
                    str[j] = str[j] - pat[j];
                    pat[j] = 0;
                }
                if(flag){
                    while(str[i] > pat[i]){
                        printf("%c", i+'a');
                        str[i]--;
                    }
                }
            }
            else{
                while(str[i] > pat[i]){
                    printf("%c", i+'a');
                    str[i]--;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
