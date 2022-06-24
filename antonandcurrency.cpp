#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    string s;
    cin >> s;
    int count_even = 0, n = s.length();
    vector<int> v;
    for(int i = 0; i < n-1; i++){
        if((s[i]-'0')%2 == 0){
            count_even++;
            v.push_back(s[i]-'0');
//            cout << v.back() << " ";
        }
    }
    if(count_even == 0){
        cout << "-1" << endl;
        return 0;
    }
    int mn = *min_element(v.begin(), v.end());
//    cout << mn << endl;
    if(mn > (s[n-1]-'0')){
        for(int i = n-2; i >= 0; i--){
            if((s[i]-'0')%2 == 0){
                char temp = s[i];
                s[i] = s[n-1];
                s[n-1] = temp;
                break;
            }
        }
    }
    else{
        for(int i = 0; i < n-1; i++){
            if((s[i]-'0')%2 == 0 && s[n-1] > s[i]){
                char temp = s[i];
                s[i] = s[n-1];
                s[n-1] = temp;
                break;
            }
        }
    }
    cout << s << endl;
    return 0;
}
