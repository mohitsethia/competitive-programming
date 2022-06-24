#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
void solve(){
    string s;
    cin >> s;
    int cnt[26] = {0};
    for(int i = 0; i < s.length(); i++){
        cnt[s[i]-'a']++;
    }
    int count_one = 0, count_more = 0;
    for(int i = 0; i < 26; i++){
        if(cnt[i] == 1){
            count_one++;
            // cout << i+1 << ": " << count_one << endl;
        }
        else{
            if(cnt[i]%2 == 0){
                count_more += cnt[i]/2;
            }
            // cout << i+1 << ": " << count_more << endl;
            else{
                count_more += (cnt[i]-3)/2;
            }
        }
    }
    if(count_more >= count_one){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}
