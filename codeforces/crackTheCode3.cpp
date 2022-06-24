#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v;
    set<int> st;
    int counter = 0;
    for(int i = 0; i < 2*n; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int k;
            cin >> k;
            v.push_back(k);
            st.insert(k);
        }
        else{
            if(*st.begin() == v.back()){
                st.erase(st.begin());
                v.pop_back();
            }
            else{
                sort(v.begin(), v.end(), greater<int>());
                v.pop_back();
                st.erase(st.begin());
                counter++;
            }
        }
    }
    cout << counter << "\n";
    return 0;
}
