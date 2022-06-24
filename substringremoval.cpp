#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> v;
        int cnt = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                cnt++;
            }
            else{
                if(cnt != 0){
                    v.push_back(cnt);
                    cnt = 0;
                }
            }
            if(i == s.length() - 1 && cnt != 0){
                v.push_back(cnt);
            }
        }
        sort(v.begin(), v.end());
        int sum = 0;
        if(v.size() % 2 == 0){
            for(int it = 0; it < v.size(); it++){
                if(it%2 != 0){
                    sum += v[it];
                }
            }
        }
        else{
            for(int it = 0; it < v.size(); it++){
                if(it%2 == 0){
                    sum += v[it];
                }
            }
        }
        cout << sum << endl;
    }
    return 0;
}
