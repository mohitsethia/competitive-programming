#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string a, b, c, d;
    bool all_equal = true;
    int type1 = 0, type2 = 0, type3 = 0;
    auto is_vowel = [&](char a){
        return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
    };
    auto get_rhyme = [&](string s, int k){
        int cnt = 0;
        string res = "";
        for(int i = s.size()-1; i >= 0; i--){
            res += s[i];
            if(is_vowel(s[i])) cnt++;
            if(cnt == k) break;
        }
        reverse(res.begin(), res.end());
        return res;
    };
    auto count_vowel = [&](string s){
        int cnt = 0;
        for(char c: s){
            if(is_vowel(c)) cnt++;
        }
        return cnt;
    };
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c >> d;
        if(count_vowel(a) < k || count_vowel(b) < k || count_vowel(c) < k || count_vowel(d) < k){
            cout << "NO\n";
            return 0;
        }
        string A = get_rhyme(a, k), B = get_rhyme(b, k), C = get_rhyme(c, k), D = get_rhyme(d, k);
        if(A != B || A != C || A != D) all_equal = false;
        if(A == B && C == D) type1++;
        if(A == C && B == D) type2++;
        if(A == D && B == C) type3++;
    }
    if(all_equal){
        cout << "aaaa\n";
    }
    else if(type1 == n){
        cout << "aabb\n";
    }
    else if(type2 == n){
        cout << "abab";
    }
    else if(type3 == n){
        cout << "abba\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
