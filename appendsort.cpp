#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
#define int long long
int countDigit(int n){
    return floor(log10(n)+1);
}
int32_t main(){
    int t, tc = 1;
    cin >> t;
    while(tc <= t){
        int n;
        cin >> n;
        vector<int> x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(x[i] < x[i-1]){
                if(countDigit(x[i]) == countDigit(x[i-1])){
                    ans++;
                    x[i] *= 10;
                }
                else{
                    string s1 = to_string(x[i]);
                    string s2 = to_string(x[i-1]);
                    if(s1[0] < s2[0]){
                        int insert = s2.size()-s1.size()+1;
                        ans += insert;
                        while(insert--){
                            s1 += '0';
                        }
                        x[i] = stoi(s1);
                    }
                    else if(s1[0] == s2[0]){
                        int j = 0, k = 0;
                        while(j < s1.length() && k < s2.length()){
                            if(s1[j] == s2[k]){
                                j++, k++;
                            }
                            else{
                                break;
                            }
                        }
                        while(k < s2.length()){
                            if(s2[k] != '9'){
                                break;
                            }
                            k++;
                        }
                        if(k == s2.length()){
                            ans += k-j+1;
                            while(j <= k){
                                if(j == k)
                                    s1 += ((s2[k-1]-'0') + 1) + '0';
                                else
                                    s1 += '0';
                                j++;
                            }
                        }
                        else{
                            ans += s2.length()-s1.length()+1;
                            if(s2[s2.length()-1] == '9'){
                                while(j <= s2.length()){
                                    s1 += '0';
                                    j++;
                                }
                            }
                            else{
                                while(j < s2.length()){
                                        s1 += '0';
                                    j++;
                                }
                            }
                        }
                        x[i] = stoi(s1);
                    }
                    else{
                        int insert = s2.size() - s1.size();
                        ans += insert;
                        while(insert--){
                            s1 += '0';
                        }
                        x[i] = stoi(s1);
                    }
                }
                
            }
            else if(x[i] == x[i-1]){
                x[i] *= 10;
                ans++;
            }
        }
        cout << "Case #" << tc++ << ": " << ans << endl;
    }
    return 0;
}

