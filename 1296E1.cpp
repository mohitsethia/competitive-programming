#include<iostream>

int main(){
    int n;
    std::string s;
    std::cin >> n >> s;
    std::string ans = "";
    char a = 'a', b = 'a';
    for(int i = 0; i < n; i++){
        if(s[i] >= a){
            ans += '0';
            a = s[i];
        }
        else if(s[i] >= b){
            ans += '1';
            b = s[i];
        }
        else{
            printf("NO\n");
            return 0;
        }
    }
    std::cout << "YES\n";
    std::cout << ans << "\n";
    return 0;
}
