#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int N;
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        int i = 0, j = 0, k = 0, curr_size = 0;
        string ans = "";
        while(i != 2*N && j != 2*N && k != 2*N){
            int count = (int) (s1[i] == '0')+(s2[j] == '0')+(s3[k] == '0');
            char ch;
            if(count >= 2){
                ans += '0';
                ch = '0';
            }
            else{
                ans += '1';
                ch = '1';
            }
            if(s1[i] == ch){
                i++;
            }
            if(s2[j] == ch){
                j++;
            }
            if(s3[k] == ch){
                k++;
            }
            curr_size++;
        }
        if(i != 2*N && 2*N-i <= 3*N-curr_size){
            ans += s1.substr(i);
        }
        else if(j != 2*N && 2*N-j <= 3*N-curr_size){
            ans += s2.substr(j);
        }
        else if(k != 2*N && 2*N-k <= 3*N-curr_size){
            ans += s3.substr(k);
        }
        for(int i = ans.size(); i < 3*N; i++){
            ans += '0';
        }
        cout << ans << endl;
    }
    return 0;
}
