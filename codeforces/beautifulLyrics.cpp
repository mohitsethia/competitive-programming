#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch  == 'u';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<string> s(n);
    vector< pair< int, pair<int, int> > > vowel_count;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        int lastChar = -1;
        int count = 0;
        for(int j = 0; j < s[i].length(); j++){
            if(s[i][j] == 'a' || s[i][j] == 'e' || s[i][j] == 'i' || s[i][j] == 'o' || s[i][j] == 'u'){
                lastChar = s[i][j] -'a';
                count++;
            }
        }
        vowel_count.push_back({lastChar, {count, i}});
    }
    sort(vowel_count.begin(), vowel_count.end(), [&](pair<int, pair<int, int> > a, pair<int, pair<int, int> > b){
        if(a.first == b.first){
            return a.second.first > b.second.first;
        }
        return a.first > b.first;
    });
    vector<pair<int, int> > v1, v2;
    int sz = vowel_count.size();
    for(int i = 0; i < sz; i++){
        int idx1 = vowel_count[i].second.second;
        if(i+1 < sz && vowel_count[i].first != -1 && vowel_count[i].second.first == vowel_count[i+1].second.first && vowel_count[i].first == vowel_count[i+1].first){
            int idx2 = vowel_count[i+1].second.second;
            v2.push_back({idx1, idx2});
            i++;
        }
        else{
            v1.push_back({vowel_count[i].second.first, idx1});
        }
    }
    sort(v1.begin(), v1.end(), [&](pair<int, int> a, pair<int, int> b){
        return a.first > b.first;
    });
    int x = 0;
    sz = v2.size();
    int y = v1.size();
    vector<pair<pair<int, int>, pair<int, int> > > ans1;
    for(int i = 0; i < y-1 && x < sz; i++){
        if(v1[i].first == v1[i+1].first){
            int idx1 = v1[i].second;
            int idx2 = v1[i+1].second;
            int idx3 = v2[x].first;
            int idx4 = v2[x].second;
            ans1.push_back({{idx1, idx2}, {idx3, idx4}});
            i++, x++;
        }
    }
    y = v2.size();
    for(int i = x; i < y-1; i+=2){
        ans1.push_back({{v2[i].first, v2[i].second}, {v2[i+1].first, v2[i+1].second}});
    }
    cout << ans1.size() << "\n";
    for(int i = 0; i < (int)ans1.size(); i++){
        cout << s[ans1[i].first.first] << " " << s[ans1[i].second.first] << "\n";
        cout << s[ans1[i].first.second] << " " << s[ans1[i].second.second] << "\n";
    }
    return 0;
}
