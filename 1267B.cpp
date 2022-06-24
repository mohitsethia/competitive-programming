#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    vector<pair<int, int> > v;
    for(int i = 0; i < (int)s.size(); i++){
        int j = i;
        while(j+1 < (int)s.size() && s[i] == s[j+1]){
            j++;
        }
        v.push_back({s[i]-'A', j-i+1});
        i = j;
    }
    int i = 0, j = v.size()-1;
    while(i < j){
        if(v[i].first != v[j].first){
            cout << "0\n";
            return 0;
        }
        if(v[i].second + v[j].second < 3){
            cout << "0\n";
            return 0;
        }
        i++;
        j--;
    }
    j = v.size();
    if(j%2 == 0){
        cout << "0\n";
        return 0;
    }
    if(v[j/2].second < 2){
        cout << "0\n";
        return 0;
    }
    cout << v[j/2].second+1 << "\n";
    return 0;
}
